cmake_minimum_required(VERSION 3.1)

# SQLiteC++ 3.x now requires C++11 compiler
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 project(LPB_SL)

 add_definitions("-std=c++17")

 include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
 conan_basic_setup()

add_subdirectory(lib)
link_directories(${LPB_SL_SOURCE_DIR}/lib/include)
link_directories(${LPB_SL_SOURCE_DIR}/lib/src)
add_executable(lpb_sl main.cpp)

target_link_libraries(lpb_sl 
    ${CONAN_LIBS} 
    lib
    )
