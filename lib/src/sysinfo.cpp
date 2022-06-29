/**
 * @file sysinfo.cpp
 * @author your name (you@domain.com)
 * @brief Provide System Information (Load,Temps,Data etc.)
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/sysinfo.hpp"
#include <sys/time.h>
#include <ctime>
#include <fmt/core.h>

std::string timeToString(std::chrono::system_clock::time_point &t)
{
    std::time_t time = std::chrono::system_clock::to_time_t(t);
    std::string time_str = std::ctime(&time);
    time_str.resize(time_str.size() - 1);
    return time_str;
}