/**
 * @file iox_lpb_backbone.cpp
 * @author Kai Staud
 * @brief Provides the main functionality. ("this is the main.cpp")
 * @version 0.1
 * @date 2022-06-17
 *
 * @copyright Copyright (c) 2022
 *
 */

//#include "fmt/core.h" // Dont include it, spdlog already does!!!
#include "lib/include/sysinfo.hpp"
#include "lib/include/tracking.hpp"
#include "lib/include/serialization.hpp"
#include "lib/include/datarouter.hpp"
#include "lib/include/datahandling.hpp"
#include "lib/include/cli.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "etl/queue_mpmc_mutex.h"
#include <chrono>
#include <thread>
using namespace tracking;
using nlohmann::json;
using namespace std::chrono_literals;
#include <iostream>

etl::queue_mpmc_mutex<ConstellationRequestMsg, 10> db_request_queue;

// Spawn a thread to run the cli on request:
void recurrent_cli()
{
   cli cl;
   // The first string needs to be the name of the binary,
   // following strings are arguments,options and parameters
   char *sargv[] = {"./iox-lpb-backbone", "clean"};
   // Allocate some memory for the input option:
   char arr[20] = "clean";
   while (true)
   {
      //std::cout << "Enter a command:";
      std::cin.getline(arr, sizeof(arr));
      sargv[1] = arr; // Copy input string into argv;
      //cl.execute(2, sargv);
      std::this_thread::sleep_for(1000ms);
   }
}

// Spawn a second thread for routing messages (not RouDI!)
void db_router()
{

   while (true)
   {
//      auto item = db_request_queue.pop();
      std::this_thread::sleep_for(1000ms);

   }
}

int main(int argc, char **argv)
{
   Datahandling::Storage st("Test");
   //  st.insert_constellation("test2");
   std::string s;

   auto logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.log", 2, 30);
   spdlog::set_default_logger(logger);
   spdlog::info("Starting Devices...");

   auto time_p = std::chrono::system_clock::now();
   fmt::print("Running Version {}.{}.{} @ {}\r\n", 0, 0, 0, timeToString(time_p));

   constellation constellation1 = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 0, 1}, {2, 3, 4}};
   constellation constellation2 = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 0, 1}, {2, 3, 4}};

   track track1;
   track1.stars.push_back(constellation1);
   track1.stars.push_back(constellation2);
   // Tracks buffern

   TaskHandler tsk;
   tsk.add_track(track1);
   tsk.pop_track();
   tsk.pop_constellation();

   track1.timestamps.push_back(1);
   track1.timestamps.push_back(2);
   json j = track1;

   Router router;

   ConstellationRequestMsg m1(1);
   Message2 m2(1.2);
   ConstellationCreateMsg m3("Hello");

   etl::send_message(router, m1);
   etl::send_message(router, ConstellationRequestMsg(2));
   etl::send_message(router, m2);
   etl::send_message(router, Message2(3.4));
   etl::send_message(router, m3);
   etl::send_message(router, ConstellationCreateMsg("World"));
   etl::send_message(router, Message4());
//router.process_queue();

      //std::thread router_thread(db_router);
      //std::thread first(recurrent_cli); // spawn new thread that calls foo()
      //first.join();
      //router_thread.join();                     // Will never join, loops over and over again!
}
