#include <etl/vector.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <chrono>
#include <sys/time.h>
#include <ctime>
#include "tracker/tracking.hpp"
#include "CLI11/CLI.hpp"

#include "nlohmann/json.hpp"
#include "string"
#include <sstream>

using namespace tracking;
using nlohmann::json;

// Serialize single star into json-struct
std::string to_json(const star &r)
{
    json j = json{

        {"star", {
                     "arm0",
                     r.arm0,
                     "arm1",
                     r.arm1,
                     "arm2",
                     r.arm2,
                     "arm3",
                     r.arm3,
                     "tcp",
                     r.tcp,
                 }},
    };
    return j.dump();
}
// Serialize complete constellation:
std::string serialize_constellation(const constellation &c)
{
    std::string result;
    result += "{";
    // Serialize each star into string:
    for (int i = 0; i < c.stars.size(); i++)
    {
        result += to_json(c.stars[i]);
        result += "#"; // Endcharacter of star
        // End of Star-Serialization
    }
    result += "},";
    // All starts done
    // "Standard" types can be serialized by API
    json j = json{
        {"timestamp", c.timestamps},
    };
    result += j.dump();
    return result;
}
star deserialize_star(std::string str)
{
    // Get string between two
    // r.id = j.at("id").get<int>();
    // r.name = j.at("name").get<std::string>();
    //     r.maxPlayers = j.at("maxPlayers").get<int>();
    //     r.timePerQuestion = j.at("timePerQuestion").get<int>();
    //     r.isActive = j.at("timePerQuestion").get<int>();
}

std::vector<std::int32_t> deserialize_timestamps(std::string str)
{
}
// Deserialize into constellations
constellation deserialize_constellation(std::string str)
{
    constellation cst;
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(str, segment, '#'))
    {
        seglist.push_back(segment);
    }
    // Pop star elements from front
    while (seglist.size() > 1)
    {
        std::string seg = seglist.front();
        seglist.erase(seglist.begin());
        cst.stars.push_back(deserialize_star(seg));
    }
    // Last remaining element is timestamp string
    deserialize_timestamps(seglist.front());
    seglist.clear(); // clear vector for new task
    return cst;
}

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
    // Serialize constellation into string:
    // RoomData r{{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 0, 1}, {2, 3, 4}}, 100};
    // std::cout << to_json(r);
    std::string str = serialize_constellation(cst);
    constellation cst_1 = deserialize_constellation(cst);
    // Save json-string in db:
    return 0;
}