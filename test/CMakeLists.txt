set (CMAKE_CXX_STANDARD 20)

include_directories( /home/kai/lpb_sl/lib/include
/home/kai/lpb_sl/external/fmt
/home/kai/lpb_sl/external/json
/home/kai/lpb_sl/external/CLI11
/home/kai/lpb_sl/external/etl
/home/kai/lpb_sl/external/SQLiteCpp
/home/kai/lpb_sl/external/blaze
/home/kai/lpb_sl/external/Catch2

)

enable_testing()
add_executable(tests forwardkinematics_test.cpp)

target_link_libraries(tests
lib
 fmt 
 CLI11 
 nlohmann_json 
 etl  
 SQLiteCpp
sqlite3
pthread
dl
blaze
Catch2::Catch2WithMain
) 
