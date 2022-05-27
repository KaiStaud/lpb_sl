#include "../datadelegate.hpp"
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