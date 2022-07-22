set (CMAKE_CXX_STANDARD 20)

include_directories( /home/kai/lpb_sl/lib/include
/home/kai/lpb_sl/external/fmt
/home/kai/lpb_sl/external/json
/home/kai/lpb_sl/external/CLI11
/home/kai/lpb_sl/external/etl
/home/kai/lpb_sl/external/blaze

)


add_library(lib
tracking.cpp 
serialization.cpp 
datahandling.cpp 
cli.cpp 
sysinfo.cpp 
datarouter.cpp 
forward_kinematics.cpp
inverse_kinematics.cpp
kalman_filter.cpp
linked_movements.cpp
)

target_link_libraries(lib
 fmt 
 CLI11 
 nlohmann_json 
 etl  
 sqlite3
pthread
dl
blaze
) 
