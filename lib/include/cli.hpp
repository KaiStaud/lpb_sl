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

#include "CLI11/CLI.hpp"
#include <string>
#include <variant>

enum class ParsingErrors
{
    no_error = 0,
    value_out_of_bound = 1,
    incorrect_input = 2,
    incorrect_format = 3,
};

class cli
{
public:
    cli();
    // Setup user shortcuts
    void init_user_shortcuts();
    // Setup developer-shortcuts
    // Shortcuts are call cli options during operation (after first parse)
    void init_dev_shortcuts();
    // set config-file: Configurateion is in ini-format (cli11 defautl)
    // if not set otherwise, the default configuration file is located under /usr/local/bin/lpb/.config
    void set_config(std::string new_config);
    // read in config-file
    void parse_config();
    // update config-file (if config changed during runtime)
    void hot_reload_config();
    /* Options */

    // Run the cli parser (again)
    int execute(int argc, char **argv);

    /* Helpers for CLI User Guidance*/
    std::variant<std::string, ParsingErrors> QueryStar(){
        
    }

    std::variant<std::string, ParsingErrors> QueryConstellation(){

    }

    std::variant<std::string, ParsingErrors> QueryTrack(){

    }

private:
    CLI::App app{"cli to control robotic arm"};
    // Create default config, if not exists
    void create_defconfig();
    // create star
    void create_star_from_cli();
    // create constellation
    void create_constellation_from_cli();
    // create track from constellations
    void create_track_from_cli();
};
