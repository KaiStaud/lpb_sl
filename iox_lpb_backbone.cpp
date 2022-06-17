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

#include "topic_data.hpp"

#include "iceoryx_hoofs/posix_wrapper/signal_watcher.hpp"
#include "iceoryx_posh/popo/subscriber.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"
//! [include]
#include "fmt/core.h"
#include "lib/include/sysinfo.hpp"
#include "lib/include/tracking.hpp"
#include "lib/include/serialization.hpp"
#include "lib/include/datarouter.hpp"
#include "lib/include/datahandling.hpp"
#include "lib/include/cli.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"

using namespace tracking;
using nlohmann::json;

#include <iostream>

int main(int argc, char **argv)
{
      Datahandling::Storage st("Test");
  st.insert_constellation("test2");

  cli debug_interface;
  debug_interface.execute(argc, argv);
std::string s;

   auto logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.log", 2, 30);
   spdlog::set_default_logger(logger);
   spdlog::info("Starting Devices...");

   auto time_p = std::chrono::system_clock::now();
   fmt::print("Running Version {}.{}.{} @ {}\r\n", 0, 0, 0, timeToString(time_p));

   star st1 = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 0, 1}, {2, 3, 4}};
   star st2 = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 0, 1}, {2, 3, 4}};

   constellation cst;
   cst.stars.push_back(st1);
   cst.stars.push_back(st2);
// Tracks buffern

   TaskHandler tsk;
   tsk.add_constellation(cst);
   tsk.pop_constellation();
   tsk.pop_stars();

   cst.timestamps.push_back(1);
   cst.timestamps.push_back(2);
   json j = cst;

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

 router.process_queue();
    //! [initialize runtime]
    constexpr char APP_NAME[] = "iox-cpp-subscriber-helloworld";
    iox::runtime::PoshRuntime::initRuntime(APP_NAME);
    //! [initialize runtime]

    //! [initialize subscriber]
    iox::popo::Subscriber<RadarObject> subscriber({"Radar", "FrontLeft", "Object"});
    //! [initialize subscriber]

    // run until interrupted by Ctrl-C
    while (!iox::posix::hasTerminationRequested())
    {
        //! [receive]
        auto takeResult = subscriber.take();
        if (!takeResult.has_error())
        {
            std::cout << APP_NAME << " got value: " << takeResult.value()->x << std::endl;
        }
        //! [receive]
        else
        {
            //! [error]
            if (takeResult.get_error() == iox::popo::ChunkReceiveResult::NO_CHUNK_AVAILABLE)
            {
                std::cout << "No chunk available." << std::endl;
            }
            else
            {
                std::cout << "Error receiving chunk." << std::endl;
            }
            //! [error]
        }

        //! [wait]
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //! [wait]
    }

    return (EXIT_SUCCESS);
}
