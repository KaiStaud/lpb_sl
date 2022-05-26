#include <../include/datahandling.hpp>

using namespace Datahandling;

struct Cached_Constellation{
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


void Serde::load_configfile()
{
}

void Serde::write_configfile()
{
}
