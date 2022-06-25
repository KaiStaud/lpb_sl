/**
 * @file tracking.hpp
 * @author Kai Staud
 * @brief Implements a multi-buffered Job-Queue
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TRACKING_H
#define TRACKING_H
#include "fmt/core.h"
#include "fmt/ranges.h"
#include <vector>
#include <etl/circular_buffer.h>
#include <optional>
struct constellation
{
    std::int32_t arm0[3];
    std::int32_t arm1[3];
    std::int32_t arm2[3];
    std::int32_t arm3[3];
    std::int32_t tcp[3];
} ;

struct track
{
    std::vector<constellation> stars;
    std::vector<std::int32_t> timestamps;
} ;

namespace tracking
{

    class TaskHandler
    {
    private:
        etl::circular_buffer<track, 10> track_buffer;
        etl::circular_buffer<constellation, 10> cst_buffer;

    public:
        TaskHandler(/* args */);
        ~TaskHandler()
        {
        }
        bool add_track(track cst);
        void pop_constellation();
        void pop_track();
    };

}
#endif