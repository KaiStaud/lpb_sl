/**
 * @file linked_movements.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/linked_movements.hpp"
#include "iostream"
using namespace linked_movements;
using namespace movement_profiles;

void trapezoidal_ramp::update_params(ramp_params new_params)
{
    params = new_params;
}

ramp_error trapezoidal_ramp::recalculate_ramp(int ramp_time, double new_position)
{
    /*Check if both ramp-up and ramp-down accelerations needs to be set at 100%*/
    diff_max = new_position - get_start_position();
    auto s = v(ramp_time, diff_max);
    // De-Acceleration phase to short!
    if (v(ramp_time, diff_max) != 0)
    {
        if ((s < params.v_max) and (ramp_time < (params.v_max / params.a_max))) // ramp_time not long enough to fully accelerate to v_max!
        {
            return ramp_error::acceleration_to_low;
        }
        else
        { // De-Acceleration phase to short ! ( speed < v_max) but time > ramp up time!
            return ramp_error::too_short_deacceleration;
        }
    }
    else
    {
        return ramp_error::no_error;
    }
    //}
    return ramp_error::no_error;
}

double trapezoidal_ramp::v(int t, double diff_position)
{
    int t_acc = params.v_max / params.a_max;
    int t_dacc = params.v_max / params.da_max;
    int t_no_acc = t_acc + (diff_position - (0.5 * t_acc * params.v_max) - (0.5 * t_dacc * params.v_max)) / params.v_max; // start of deacceleration
    if ((t > t_acc) and (t < t_dacc))                                                                                     // t during const acceleration
    {
        return params.v_max;
    }
    else if (t < t_acc) // t during positive acceleration
    {
        return params.a_max * t + get_start_speed();
    }
    else // t during negative acceleration
    {
        // Calculate the deacceleration time:
        return params.v_max - params.da_max * (t - t_no_acc);
    }
}

double trapezoidal_ramp::get_start_position()
{
    return 0;
}
double trapezoidal_ramp::get_start_speed()
{
}
void sync_manager::link_child(movement_profiles::generic_ramp *new_child)
{
    childs.push_back(new_child);
}

void sync_manager::synchronize_childs(int sync_time)
{
}