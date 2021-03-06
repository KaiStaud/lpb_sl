/**
 * @file datahandling.cpp
 * @author your name (you@domain.com)
 * @brief Implementation of DB Handling and Startup data
 * @version 0.1
 * @date 2022-04-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/datahandling.hpp"
#include "fmt/color.h"
#include <iostream>
#include <sqlite3.h>

using namespace Datahandling;
struct Cached_Constellation
{
    int id;
    std::string blob;
};

Storage::Storage(std::string db_path)
{
    char *zErrMsg = 0;
    int rc;
    char *sql;

    /* Open database */
    rc = sqlite3_open("constellations.sqlite", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
    }
}

Serde::Serde()
{
}

void Storage::setup_storage()
{
}

void Storage::get_bootparams()
{
}
void Storage::set_bootparams()
{
}
void Storage::spin_off()
{
}

static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

void Storage::get_by_id(std::int16_t id)
{
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    const char *data = "Callback function called";
    /* Create SQL statement */
    std::string s_sql = "SELECT * from SERDE_CONSTELLATIONS where ID=" + std::to_string(id);
    sql = s_sql.c_str();
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,"SQL Error: {}!\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Operation done successfully\n");
    }
}

void Storage::generic_insert(const std::string table, const std::string s)
{
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    const char *data = "Callback function called";
    /* Create SQL statement */
    std::string s_sql = "insert into " + table + " (BLOB) VALUES('" + s + "')";
    sql = s_sql.c_str();
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,"SQL Error: {}!\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
        ;
}

void Serde::load_configfile()
{
}

void Serde::write_configfile()
{
}
