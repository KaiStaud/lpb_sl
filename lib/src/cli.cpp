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
#include <../include/cli.hpp>
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
    auto create_star = app.add_subcommand("create-start", "Create a new star");
    auto create_constellation = app.add_subcommand("create-cst", "Create a new constellation");
    auto create_track = app.add_subcommand("create-track", "Create a complete track");
    auto define_config = app.add_subcommand("defconfig", "Use different defconfig");
    auto shutdown = app.add_subcommand("shutdown", "Shutdown system,return to home");

    create_star->callback([&]() {});
    create_constellation->callback([&]() {});
    create_track->callback([&]() {});
    define_config->callback([&]() {});
    shutdown->callback([&]() {});
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