#include <etl/vector.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <chrono>
#include <sys/time.h>
#include <ctime>
#include "lib/include/tracking.hpp"
#include "lib/include/serialization.hpp"
#include <sqlite_orm/sqlite_orm.h>
#include "CLI11/CLI.hpp"
#include "string"

#include <thread>
#include <mutex>
#include <condition_variable>

using namespace tracking;
using nlohmann::json;

std::mutex m;
std::mutex read_lock;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

struct Cached_Constellation{
    int id;
    std::string blob;
};

std::string timeToString(std::chrono::system_clock::time_point &t)
{
    std::time_t time = std::chrono::system_clock::to_time_t(t);
    std::string time_str = std::ctime(&time);
    time_str.resize(time_str.size() - 1);
    return time_str;
}

// This thread runs the database:
void data_thread(){

    // Set up the database:
    using namespace sqlite_orm;

    auto db = make_storage("constellations.sqlite",
                                make_table("SERDE_CONSTELLATIONS",
                                           make_column("ID", &Cached_Constellation::id, primary_key()),
                                           make_column("BLOB", &Cached_Constellation::blob)));

    db.sync_schema();
    db.remove_all<Cached_Constellation>();
    // Wait for condition variable:
    // Other threads request an action on a constellation
       // Wait until main() sends data
    std::unique_lock lk(m);
    cv.wait(lk, []{return ready;});
 
    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    fmt::print("Received data : {}\r\n",data);
    data = " new data after processing";

    // Action Request received! Decide what to do:
    // Insert:  
    db.insert( Cached_Constellation{ -1,data});

    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";
    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();


    // Read back:
    //std::unique_lock read_lk(m);
    //cv.wait(read_lk, []{return read_ready;}); // Are we allowed to read data?
    //read_lk.unlock();
    /*
    cout << "---------------------" << endl;
    for(auto& serialized_constellation: db.iterate<Cached_Constellation>()) {
        cout << db.dump(serialized_constellation) << endl;
    }
    // Deserialize constellation and put it into ringbuffer:
    */
    // Notify MQTT-Client that jobs are queued in"
    
}
int main(int argc, char **argv)
{
    CLI::App app{"cli to control robotic arm"};
    app.require_subcommand(1);

    auto move_tcp = app.add_subcommand("tcp", "Move tcp to passed vector");

    bool add_delay;
    move_tcp->add_flag("-d,--delay", add_delay, "delay movement");
    move_tcp->add_flag("-s,--store", add_delay, "save to database");

    std::vector<std::string> coordinates;
    move_tcp->add_option("files", coordinates, "Coordinates");

    move_tcp->callback([&]()
                       {
    if(coordinates.empty()) {
        if(add_delay)
        {
            fmt::print("Delaying job for 10 seconds");
        }
        else
            std::cout << "Nothing to todo :(";
    } else {
            fmt::print("Spezified coordinates {}",coordinates);
    } });

    CLI11_PARSE(app, argc, argv);

    auto time_p = std::chrono::system_clock::now();
    fmt::print("Running Version {}.{}.{} @ {}\r\n", 0, 0, 0, timeToString(time_p));

    star st1 = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 0, 1}, {2, 3, 4}};
    star st2 = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 0, 1}, {2, 3, 4}};

    constellation cst;
    cst.stars.push_back(st1);
    cst.stars.push_back(st2);
    // Tracks buffern
    fmt::print("pushing two tracks into buffer....\r\n");

    TaskHandler tsk;
    tsk.add_constellation(cst);
    tsk.pop_constellation();
    tsk.pop_stars();

    cst.timestamps.push_back(1);
    cst.timestamps.push_back(2);
    json j = cst;
    std::cout << std::setw(4) << j << "\n\n";

// Spin off a thread for handling database actions:
   std::thread worker(data_thread);
 
    data = j.dump();
    // send data to the worker thread
    {
        std::lock_guard lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();
 
    // wait for the worker
    {
        std::unique_lock lk(m);
        cv.wait(lk, []{return processed;});
    }
    worker.join();
    return 0; 
}