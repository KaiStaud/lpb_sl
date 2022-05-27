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

#include "lib/include/DataRouter.hpp"
using namespace tracking;
using nlohmann::json;

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

   Router router;

  ConstellationRequestMsg m1(1);
  Message2 m2(1.2);
  ConstellationAnswerMsg m3("Hello");

  etl::send_message(router, m1);
  etl::send_message(router, ConstellationRequestMsg(2));
  etl::send_message(router, m2);
  etl::send_message(router, Message2(3.4));
  etl::send_message(router, m3);
  etl::send_message(router, ConstellationAnswerMsg("World"));
  etl::send_message(router, Message4());

  std::cout << std::endl;

  router.process_queue();
    return 0; 
}