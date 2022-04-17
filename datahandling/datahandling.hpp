#include <string>
#include <tracker/tracking.hpp>
namespace Datahandling
{

    class Storage
    {
        Storage(std::string db_path);
        void setup_storage();
        void get_bootparams();
        void set_bootparams();
        void add_track();
        void get_track();
    };

    class Serde
    {
        Serde();
        void load_configfile();
        void write_configfile();
    };

}