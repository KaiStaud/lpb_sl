/**
 * @file datahandling.hpp
 * @author Kai Staud
 * @brief Abstract SQLite3 and provides Startup Data
 * @version 0.1
 * @date 2022-04-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef DATAHANDLING_H
#define DATAHANDLING_H

#include <string>
#include "tracking.hpp"
#include <sqlite3.h>

namespace Datahandling
{

    struct Cached_Constellation
    {
        int id;
        std::string blob;
    };

    class Storage
    {
    public:
        Storage(std::string db_path);
        void setup_storage();
        void get_bootparams();
        void set_bootparams();
        void spin_off();
        void get_by_id(std::int16_t id);
        void generic_insert(const std::string table,const std::string s);

        void open_db();

    private:
        sqlite3 *db;
    };
    class Serde
    {
        Serde();
        void load_configfile();
        void write_configfile();
    };

}
#endif