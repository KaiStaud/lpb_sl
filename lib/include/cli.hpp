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

using namespace tracking;

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
    /* Transfer functions from cli to db.
        The database may be busy and/or locked by other threads.
    */
    void try_create_star();          /**< Create a star*/
    void try_create_constellation(); /**< Create a constellaton*/
    void try_create_track();         /**< Create a star*/

private:
    // Bind methods with std::function
    void create_defconfig(); /**< Create default config, if not exists */

//     std::variant<star, ParsingErrors> QueryStar(); /**< Read in star from command line */
//     std::variant<constellation, ParsingErrors> QueryConstellation(std::uint8_t num_stars = 3); /**< Read in complete constellation */
//     std::variant<track, ParsingErrors> QueryTrack(std::uint8_t num_constellations = 1); /** < Create complete Track from cli */
   star query_star(); /**< Read in star from command line */
   constellation query_constellation(std::uint8_t num_stars = 3); /**< Read in complete constellation */
   track query_track(std::uint8_t num_constellations = 1); /** < Create complete Track from cli */
};

