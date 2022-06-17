// Shared Datatypes between each applications:
#include "topic_data.hpp"

// Iceoryx includes:
#include "iceoryx_hoofs/posix_wrapper/signal_watcher.hpp"
#include "iceoryx_posh/popo/publisher.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"

// LPBs includes:
#include <iostream>

#include "lib/include/cli.hpp"

int main(int argc, char **argv)
{
    cli debug_interface;
    debug_interface.execute(argc, argv);
    //! [initialize runtime]
    constexpr char APP_NAME[] = "iox-cpp-publisher-helloworld";
    iox::runtime::PoshRuntime::initRuntime(APP_NAME);
    //! [initialize runtime]

    //! [create publisher]
    iox::popo::Publisher<RadarObject> publisher({"Radar", "FrontLeft", "Object"});
    //! [create publisher]

    double ct = 0.0;
    //! [wait for term]
    while (!iox::posix::hasTerminationRequested())
    //! [wait for term]
    {
        ++ct;

        // Retrieve a sample from shared memory
        //! [loan]
        auto loanResult = publisher.loan();
        //! [loan]
        //! [publish]
        if (!loanResult.has_error())
        {
            auto &sample = loanResult.value();
            // Sample can be held until ready to publish
            sample->x = ct;
            sample->y = ct;
            sample->z = ct;
            sample.publish();
        }
        //! [publish]
        //! [error]
        else
        {
            auto error = loanResult.get_error();
            // Do something with error
            std::cerr << "Unable to loan sample, error code: " << error << std::endl;
        }
        //! [error]

        //! [msg]
        std::cout << APP_NAME << " sent value: " << ct << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //! [msg]
    }

    return 0;
}
