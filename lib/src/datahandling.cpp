#include <../include/datahandling.hpp>
#include <iostream>
#include "../../SQLiteCpp/include/SQLiteCpp/SQLiteCpp.h"

SQLite::Database db("constellations.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

using namespace Datahandling;

struct Cached_Constellation
{
    int id;
    std::string blob;
};

Storage::Storage(std::string db_path)
{
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
void Storage::get_by_id()
{    
    SQLite::Statement   query(db, "SELECT * FROM SERDE_CONSTELLATIONS");

        // Loop to execute the query step by step, to get rows of result
    while (query.executeStep())
    {
        // Demonstrate how to get some typed column value
        int         id      = query.getColumn(0);
        const char* value   = query.getColumn(1);
      
        std::cout << "row: " << id << ", " << value << ", " << std::endl;
    }
}

void Storage::insert_constellation(std::string s)
{
    // Begin transaction
    SQLite::Transaction transaction(db);

    //    db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");

    int nb = db.exec("INSERT INTO SERDE_CONSTELLATIONS VALUES (3, \"tsest\")");
    std::cout << "INSERT INTO test VALUES (3, \"test\")\", returned " << nb << std::endl;
    transaction.commit();

}

void Serde::load_configfile()
{
}

void Serde::write_configfile()
{
}
