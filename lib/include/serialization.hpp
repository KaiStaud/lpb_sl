/**
 * @file serialization.hpp
 * @author Kai Staud
 * @brief Serialize Positions into JSON
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SERIALIZATION_H
#define SERIALIZATION_H
#include "nlohmann/json.hpp"
#include "string"
#include "tracking.hpp"
using namespace tracking;

using nlohmann::json;
void to_json(json &j, const tstar &s);
void from_json(const json &j, tstar &s);
void to_json(json &j, const constellation &s);
void from_json(const json &j, constellation &s);
void to_json(json &j, const track &s);
void from_json(const json &j, track &s);

#endif