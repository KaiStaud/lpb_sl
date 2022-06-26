# Copyright (c) 2021 - 2022 by Apex.AI Inc. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

# Build icehello example
cmake_minimum_required(VERSION 3.13)
project(example_icehello)
set (CMAKE_CXX_STANDARD 20)
include(GNUInstallDirs)

find_package(iceoryx_posh CONFIG REQUIRED)
find_package(iceoryx_hoofs CONFIG REQUIRED)

get_target_property(ICEORYX_CXX_STANDARD iceoryx_posh::iceoryx_posh CXX_STANDARD)
include(IceoryxPlatform)
include(IceoryxPackageHelper)

iox_add_executable(
    TARGET  iox-lpb-cli
    FILES   ./iox_lpb_cli.cpp
    LIBS    iceoryx_posh::iceoryx_posh
)

iox_add_executable(
    TARGET  iox-lpb-backbone
    FILES   ./iox_lpb_backbone.cpp
    LIBS    iceoryx_posh::iceoryx_posh
)

target_compile_features(iox-lpb-cli PRIVATE cxx_std_17)
target_compile_features(iox-lpb-backbone PRIVATE cxx_std_17)

add_subdirectory(lib)
link_directories(${ICEORYX_TEST_SOURCE_DIR}/lib/include)
link_directories(${ICEORYX_TEST_SOURCE_DIR}/lib/src)

add_subdirectory(external/CLI11)
add_subdirectory(external/fmt)
add_subdirectory(external/json)
add_subdirectory(external/spdlog)
add_subdirectory(external/etl)
add_subdirectory(external/SQLiteCpp)
add_subdirectory(external/CppGPIO)
add_subdirectory(external/magic_enum)


target_include_directories(iox-lpb-backbone
PUBLIC external/fmt
PUBLIC external/json
PUBLIC external/spdlog
PUBLIC external/CLI11
PUBLIC lib/include)

target_link_libraries(iox-lpb-backbone 
    lib
    )

target_link_libraries(iox-lpb-cli 
lib
)