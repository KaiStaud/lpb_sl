#include "lib/include/datadelegate.hpp"

    using namespace sqlite_orm;

    auto db = make_storage("constellations.sqlite",
                                make_table("SERDE_CONSTELLATIONS",
                                           make_column("ID", &Cached_Constellation::id, primary_key()),
                                           make_column("BLOB", &Cached_Constellation::blob)));

void init_storage(){
     db.sync_schema();
    db.remove_all<Cached_Constellation>();   
}

void add_constellation(std::string data){
    db.insert( Cached_Constellation{ -1,data});
}

void get_constellation(){
    for(auto& serialized_constellation: db.iterate<Cached_Constellation>()) {
        cout << db.dump(serialized_constellation) << endl;
    }
}
