/**
 * @file serialization.cpp
 * @author Kai Staud
 * @brief Implements SERDES functionality for Nlohmanns JSON lib
 * @version 0.1
 * @date 2022-04-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/serialization.hpp"
void to_json(json &j, const tstar &s)
{
    j = json{
        {"xyz", {s.xyz}},

    };
}

void from_json(const json &j, tstar &s)
{
       j.at("xyz").get_to(s.xyz);
 
}
void to_json(json &j, const constellation &s)
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

void from_json(const json &j, constellation &s)
{
    // j.at("name").get_to(s.name);
    j.at("arm0").get_to(s.arm0);
    j.at("arm1").get_to(s.arm1);
    j.at("arm2").get_to(s.arm2);
    j.at("arm3").get_to(s.arm3);
    j.at("tcp").get_to(s.tcp);
    // j.at("id").get_to(s.id);
}

void to_json(json &j, const track &s)
{
    j = json{
        {"stars", {s.stars}},
        {"timestamps", {s.timestamps}},
        //{"track_name", s.track_name},
        //{"track_id", s.track_id},
    };
}

void from_json(const json &j, track &s)
{
    j.at("stars").get_to(s.stars);
    j.at("timestamps").get_to(s.timestamps);
    // j.at("track_name").get_to(s.track_name);
    // j.at("track_id").get_to(s.track_id);
}
