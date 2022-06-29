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
// struct star
// {
//     std::int32_t arm0[3];
//     std::int32_t arm1[3];
//     std::int32_t arm2[3];
//     std::int32_t arm3[3];
//     std::int32_t tcp[3];
// } ;

// struct constellation
// {
//     std::vector<star> stars;
//     std::vector<std::int32_t> timestamps;
// } ;
/**
 * @brief Abstracts an array into an new datatype
 * 
 */
struct tstar{
std::int32_t xyz[3];
};

struct tconstellation
{
    std::vector<tstar> tstars;

} ;

/**
 * @brief Structure encapsulation several stars
 * 
 */
struct constellation
{
    std::int32_t arm0[3];
    std::int32_t arm1[3];
    std::int32_t arm2[3];
    std::int32_t arm3[3];
    std::int32_t tcp[3];
} ;

/**
 * @brief Structure encapsuling a constellation with a seperated timestamp
 * 
 */
struct track
{
    std::vector<constellation> stars;
    std::vector<std::int32_t> timestamps;
} ;

namespace tracking
{
/**
 * @brief Class for Deploying and commiting jobs.
 * Jobs are buffered in multiple stages
 */
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