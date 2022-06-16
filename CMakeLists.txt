cmake_minimum_required(VERSION 2.8.12)
 project(LPB_SL)

 add_definitions("-std=c++17")

 include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
 conan_basic_setup()

# Add SQLite3 C++ wrapper around sqlite3 library (and sqlite3 itself provided for ease of use)
# Here you can set CMake variables to avoid building Example, as well as cpplint, cppcheck...
# or set them in the cmake command line (see for instance provided build.bat/build.sh scripts)
set(SQLITECPP_RUN_CPPCHECK OFF CACHE BOOL "" FORCE)
set(SQLITECPP_RUN_CPPLINT OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp)
 add_subdirectory(lib)
 link_directories(${LPB_SL_SOURCE_DIR}/lib/include)
 link_directories(${LPB_SL_SOURCE_DIR}/lib/src)
 add_executable(lpb_sl main.cpp)
 target_link_libraries(lpb_sl ${CONAN_LIBS} lib SQLiteCpp)