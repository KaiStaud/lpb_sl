#include "../include/tracking.hpp"
#include "fmt/core.h"

using namespace tracking;

TaskHandler::TaskHandler()
{
}

void TaskHandler::pop_constellation()
{
    auto popped_cst = cst_buffer.front();
    cst_buffer.pop();

    // Extract all starts from constellation, and push them into stars:
    while (popped_cst.stars.size() > 0)
    {
        star_buffer.push(popped_cst.stars.front());
        popped_cst.stars.erase(popped_cst.stars.begin());
    }
}

void TaskHandler::pop_stars()
{
    // star poppen und als neues ziel setzen
    auto new_destination_star = star_buffer.front();
    star_buffer.pop();
    fmt::print("popped star from queue and set it ...\r\n");
    fmt::print("{} {} {} {} {}\n", new_destination_star.arm0,
               new_destination_star.arm1,
               new_destination_star.arm2,
               new_destination_star.arm3,
               new_destination_star.tcp);
}

bool TaskHandler::add_constellation(constellation cst)
{
    cst_buffer.push(cst);
    return true;
}
