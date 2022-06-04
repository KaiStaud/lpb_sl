/*
* Provides System Information:
* - Version, System Time
* - IO and CPU Load
* - IO Configuration and Errors
*/

#include <chrono>
#include <string>

std::string timeToString(std::chrono::system_clock::time_point &t);
