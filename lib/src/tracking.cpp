/**
 * @file tracking.cpp
 * @author your name (you@domain.com)
 * @brief Implemenation of Progress Tracking,multi-buffering
 * @version 0.1
 * @date 2022-04-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/tracking.hpp"
#include "blaze/Math.h"
#include "fmt/core.h"
using namespace tracking;

TaskHandler::TaskHandler()
{
}

void TaskHandler::pop_track()
{
    auto popped_track = track_buffer.front();
    track_buffer.pop();

    // Extract all starts from constellation, and push them into stars:
    while (popped_track.stars.size() > 0)
    {
        cst_buffer.push(popped_track.stars.front());
        popped_track.stars.erase(popped_track.stars.begin());
    }
}

void TaskHandler::pop_constellation()
{
    // star poppen und als neues ziel setzen
    auto new_constellation = cst_buffer.front();
    cst_buffer.pop();
    fmt::print("popped star from queue and set it ...\r\n");
    fmt::print("{} {} {} {} {}\n", new_constellation.arm0,
               new_constellation.arm1,
               new_constellation.arm2,
               new_constellation.arm3,
               new_constellation.tcp);
}

bool TaskHandler::add_track(track cst)
{
    track_buffer.push(cst);
    return true;
}

