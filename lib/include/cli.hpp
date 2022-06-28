/**
 * @file cli.hpp
 * @author Kai Staud
 * @brief Provide user and dev options to control ECU
 * @version 0.1
 * @date 2022-06-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <string>
#include <variant>
#include "fmt/core.h"
#include "tracking.hpp"
#include "serialization.hpp"
#include <iostream>
#include <vector>

enum class ParsingErrors
{
    no_error = 0,
    value_out_of_bound = 1,
    incorrect_input = 2,
    incorrect_format = 3,
};
/**
 * @brief Abstraction class for cli functionality
 *
 */
class cli
{
public:
    cli();
    // Setup user shortcuts
    void init_user_shortcuts();              /**< simple user interface functions  */
    void init_dev_shortcuts();               /**< Extended functions for rt-debugging */
    void set_config(std::string new_config); /**< Optional ini-file configuration, default: /usr/local/bin/.config*/
    void parse_config();                     /*<< Parse configuration with hot-reload */
    void hot_reload_config();                /*< check if file changed */
    /* Options */

    int execute(int argc, char **argv); /**< Run the cli parser (again) */

    std::variant<star, ParsingErrors> QueryStar() /**< Read in star from command line */
    {
        const std::string fmt_inputs[3] = {"x", "y", "z"};
        std::string num_as_string;
        star st;
        for (int i = 0; i < 3; i++)
        {
            fmt::print("Enter {} Coordinate: ", fmt_inputs[i]);
            getline(std::cin, num_as_string);
            try
            {
                st.xyz[i] = std::stoi(num_as_string);
            }
            catch (std::invalid_argument)
            {
                return ParsingErrors::incorrect_input;
            }
        }
        return st;
    }

    std::variant<constellation, ParsingErrors> QueryConstellation(std::uint8_t num_stars = 3) /**< Read in complete constellation */
    {
        constellation cst;
        tconstellation tcst;
        try
        {
            for (int i = 0; i < num_stars; i++)
            {
                fmt::print("Enter Coordinates for star no {}: ", i);
                auto what = QueryStar();
                auto res = std::get<star>(what);
                tcst.tstars.push_back(res);
            }
        }
        catch (std::bad_variant_access const &ex)
        {
            fmt::print("Unable to parse Constellation {}", ex.what());
        }
        return cst;
    }

    std::variant<track, ParsingErrors> QueryTrack(std::uint8_t num_constellations = 1) /** < Create complete Track from cli */
    {
        track t;
        try
        {
            for (int i = 0; i < num_constellations; i++)
            {
                fmt::print("Enter Constellation no {}: ", i);
                auto res = QueryConstellation();
                auto cst = std::get<constellation>(res);
                t.stars.push_back(cst);
            }
        }
        catch (std::bad_variant_access const &ex)
        {
            fmt::print("Unable to parse Constellation {}", ex.what());
        }
        return t;
    }

private:
    void create_defconfig(); /**< Create default config, if not exists */
};
