#include <fmt/core.h>
#include "lib/include/sysinfo.hpp"
#include "lib/include/tracking.hpp"
#include "lib/include/serialization.hpp"
#include <sqlite_orm/sqlite_orm.h>
#include "lib/include/datarouter.hpp"
#include "lib/include/cli.hpp"

using namespace tracking;
using nlohmann::json;

struct Cached_Constellation{
    int id;
    std::string blob;
};

int main(int argc, char **argv)
{
    cli debug_interface;
    debug_interface.execute(argc,argv);

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
  ConstellationCreateMsg m3("Hello");

  etl::send_message(router, m1);
  etl::send_message(router, ConstellationRequestMsg(2));
  etl::send_message(router, m2);
  etl::send_message(router, Message2(3.4));
  etl::send_message(router, m3);
  etl::send_message(router, ConstellationCreateMsg("World"));
  etl::send_message(router, Message4());

  std::cout << std::endl;

  router.process_queue();
    return 0; 
}