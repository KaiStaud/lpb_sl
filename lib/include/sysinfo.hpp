/**
 * @file sysinfo.hpp
 * @author Kai Staud
 * @brief Provides System Information for Log-Information
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <chrono>
#include <string>

std::string timeToString(std::chrono::system_clock::time_point &t);
