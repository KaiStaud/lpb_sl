#include "../include/bufferedlogger.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
using namespace Logging;

BufferedLogger::BufferedLogger(){

}

void BufferedLogger::SetLogFile(std::string f){
    // Create a file rotating logger with 5mb size max and 3 rotated files
    auto max_size = 1048576 * 5;
    auto max_files = 3;
    auto logger = spdlog::rotating_logger_mt("some_logger_name", "logs/rotating.txt", max_size, max_files);
} 

void BufferedLogger::PrintAboveLevel(LogLevel l){

}