/**
 * @file cli.cpp
 * @author Kai Staud
 * @brief Module to dynamicaly debug LPBs ECU Host
 * @version 0.1
 * @date 2022-06-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/cli.hpp"
#include "../include/tracking.hpp"
#include "../include/serialization.hpp"
#include "../include/datarouter.hpp"
#include "../include/datahandling.hpp"
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <variant>
#include "CLI11/CLI.hpp"

CLI::App app{"cli to control robotic arm"};

cli::cli()
{
     set_config("/usr/bin/lpb/.config");
     parse_config();
     init_dev_shortcuts();
     init_user_shortcuts();
}

void cli::init_user_shortcuts()
{
     app.require_subcommand(1);

     auto move_tcp = app.add_subcommand("tcp", "Move tcp to passed vector");
     auto create_star = app.add_subcommand("create-star", "Create a new star");
     auto create_constellation = app.add_subcommand("create-cst", "Create a new constellation");
     auto create_track = app.add_subcommand("create-track", "Create a complete track");
     auto define_config = app.add_subcommand("defconfig", "Use different defconfig");
     auto shutdown = app.add_subcommand("shutdown", "Shutdown system,return to home");
     auto shutdown_cli = app.add_subcommand("shutdown-cli", "Shutdown cli system");
     auto run_program = app.add_subcommand("run-program", "Run {track/star/constellation/universe}");

     create_star->callback([&]()
                           { try_create_star(); });
     create_constellation->callback([&]()
                                    { try_create_constellation(); });
     create_track->callback([&]()
                            { try_create_track(); });
     define_config->callback([&]() {});
     shutdown->callback([&]() {});
}

void cli::try_create_star()
{
     auto what = query_star();
     try
     {
          auto res = std::get<tstar>(what); // Throws if error was returned
          json j = res;
          etl::send_message(router, ConstellationCreateMsg(j.dump()));
     }

     catch (std::bad_variant_access const &ex) // Catch previously thrown wrong-type errors
     {
          fmt::print("Unable to parse Star {}", ex.what());
     }
}

void cli::try_create_constellation()
{
     auto what = query_constellation();
     try
     {
          auto res = std::get<constellation>(what); // Throws if error was returned
          json j = res;
          etl::send_message(router, ConstellationCreateMsg(j.dump()));
     }

     catch (std::bad_variant_access const &ex) // Catch previously thrown wrong-type errors
     {
          fmt::print("Unable to parse Constellation {}", ex.what());
     }
}

void cli::try_create_track()
{
     auto what = query_track();
     try
     {
          auto res = std::get<track>(what); // Throws if error was returned
          json j = res;
          etl::send_message(router, ConstellationCreateMsg(j.dump()));
     }

     catch (std::bad_variant_access const &ex) // Catch previously thrown wrong-type errors
     {
     }
}

void cli::init_dev_shortcuts()
{
     auto clean = app.add_subcommand("clean", "Clean db and config");
     auto reinit = app.add_subcommand("reinit", "Re-Initialize system");
     auto delete_errors = app.add_subcommand("delete-errors", "Delete errors");
     auto no_crypt = app.add_subcommand("no-crypt", "Run without encrypted comms");
     auto watch_pdo = app.add_subcommand("pdo", "Watch PDOs while running");
     // Callbacks:
     clean->callback([&]() {});
     reinit->callback([&]() {});
     delete_errors->callback([&]() {});
     no_crypt->callback([&]() {});
     watch_pdo->callback([&]() {});
}

void cli::set_config(std::string new_config)
{
     app.set_config("--config")->transform(CLI::FileOnDefaultPath("/usr/bin/lpb_sl/.config"));
}
void cli::parse_config()
{
}

void cli::hot_reload_config()
{
}

int cli::execute(int argc, char **argv)
{
     CLI11_PARSE(app, argc, argv);
     return 0;
}

std::variant<tstar, ParsingErrors> cli::query_star(std::istream &stream) /**< Read in star from command line */
{
     const std::string fmt_inputs[3] = {"x", "y", "z"};
     std::string num_as_string;
     tstar st;
     for (int i = 0; i < 3; i++)
     {
          fmt::print("Enter {} Coordinate: ", fmt_inputs[i]);
          getline(stream, num_as_string);
          try
          {
               st.xyz[i] = std::stoi(num_as_string);
          }
          catch (std::invalid_argument) // Char or string?
          {
               return ParsingErrors::incorrect_input;
          }
     }
     return st;
}

std::variant<constellation, ParsingErrors> cli::query_constellation(std::uint8_t num_stars) /**< Read in complete constellation */
{
     constellation cst;
     tconstellation tcst;
     try
     {
          for (int i = 0; i < num_stars; i++)
          {
               fmt::print("Enter Coordinates for star no {}: ", i);
               auto what = query_star();
               auto res = std::get<tstar>(what); // Throws if error was returned
               tcst.tstars.push_back(res);
          }
     }
     catch (std::bad_variant_access const &ex) // Catch previously thrown wrong-type errors
     {
          fmt::print("Unable to parse Constellation {}", ex.what());
     }
     return cst;
}

std::variant<track, ParsingErrors> cli::query_track(std::uint8_t num_constellations) /** < Create complete Track from cli */
{
     track t;
     try
     {
          for (int i = 0; i < num_constellations; i++)
          {
               fmt::print("Enter Constellation no {}: ", i);
               auto res = query_constellation();
               auto cst = std::get<constellation>(res); // Throws if error was returned
               t.stars.push_back(cst);
          }
     }
     catch (std::bad_variant_access const &ex) // Catch previously thrown wrong-type errors
     {
          fmt::print("Unable to parse Constellation {}", ex.what());
     }
     return t;
}