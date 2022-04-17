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

using namespace tracking;
using nlohmann::json;

// (Deserialize a star)
void to_json(json &j, const star &s);
void from_json(const json &j, star &s);
// (De)Serialize a constellation
void to_json(json &j, const constellation &s);
void from_json(const json &j, constellation &s);

std::string timeToString(std::chrono::system_clock::time_point &t)
{
    std::time_t time = std::chrono::system_clock::to_time_t(t);
    std::string time_str = std::ctime(&time);
    time_str.resize(time_str.size() - 1);
    return time_str;
}

void to_json(json &j, const star &s)
{
    j = json{
        //{"name", s.name},
        {"arm0", s.arm0},
        {"arm1", s.arm1},
        {"arm2", s.arm2},
        {"arm3", s.arm3},
        {"tcp", s.tcp},
        //{"id", s.id}
    };
}

void from_json(const json &j, star &s)
{
    // j.at("name").get_to(s.name);
    j.at("arm0").get_to(s.arm0);
    j.at("arm1").get_to(s.arm1);
    j.at("arm2").get_to(s.arm2);
    j.at("arm3").get_to(s.arm3);
    j.at("tcp").get_to(s.tcp);
    // j.at("id").get_to(s.id);
}

void to_json(json &j, const constellation &s)
{
    j = json{
        {"stars", {s.stars}},
        {"timestamps", {s.timestamps}},
        //{"track_name", s.track_name},
        //{"track_id", s.track_id},
    };
}

void from_json(const json &j, constellation &s)
{
    j.at("stars").get_to(s.stars);
    j.at("timestamps").get_to(s.timestamps);
    // j.at("track_name").get_to(s.track_name);
    // j.at("track_id").get_to(s.track_id);
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
    return 0;
}