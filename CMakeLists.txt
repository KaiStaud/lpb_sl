cmake_minimum_required(VERSION 2.8.12)
 project(LPB_SL)

 add_definitions("-std=c++11")

 include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
 conan_basic_setup()

 add_subdirectory(tracker)
 add_subdirectory(serialization)

 add_executable(lpb_sl main.cpp)
 target_link_libraries(lpb_sl ${CONAN_LIBS} tracker serialization )