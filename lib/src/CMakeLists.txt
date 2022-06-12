include_directories( ${LPB_SL_SOURCE_DIR}/lib/include)

add_library(lib tracking.cpp serialization.cpp datahandling.cpp cli.cpp sysinfo.cpp datarouter.cpp bufferedlogger.cpp)
