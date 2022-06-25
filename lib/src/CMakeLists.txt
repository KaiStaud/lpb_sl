set (CMAKE_CXX_STANDARD 20)

include_directories( /home/kai/iceoryx_test/lib/include
/home/kai/iceoryx_test/external/fmt
/home/kai/iceoryx_test/external/json
/home/kai/iceoryx_test/external/spdlog
/home/kai/iceoryx_test/external/CLI11
/home/kai/iceoryx_test/external/etl
/home/kai/iceoryx_test/external/SQLiteCpp
)


add_library(lib
tracking.cpp 
serialization.cpp 
datahandling.cpp 
cli.cpp 
sysinfo.cpp 
datarouter.cpp 
)

target_link_libraries(lib
 fmt 
 spdlog 
 CLI11 
 nlohmann_json 
 etl  
 SQLiteCpp
sqlite3
pthread
dl) 
