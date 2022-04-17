#include "nlohmann/json.hpp"
#include "string"
#include "tracking.hpp"
using namespace tracking;
using nlohmann::json;

void to_json(json &j, const star &s);
void from_json(const json &j, star &s);
void to_json(json &j, const constellation &s);
void from_json(const json &j, constellation &s);
