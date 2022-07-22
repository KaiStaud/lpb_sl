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

    // Acceleration to slow: Position not reached even with full acceleration!
    if (diff_max > 0.5 * ramp_time * params.a_max)
    {
        return ramp_error::acceleration_to_low;
    }
    else
    {
        // De-Acceleration phase to short!
        if (v(ramp_time, diff_max) != 0)
        {
            return ramp_error::too_short_deacceleration;
        }
        else
        {
            return ramp_error::no_error;
        }
    }
    return ramp_error::no_error;
}

double trapezoidal_ramp::v(int t, double diff_position)
{
    int t_acc = params.v_max / params.a_max;
    int t_dacc = params.v_max / params.da_max;

    if ((t > t_acc) and (t < t_dacc))
    {
        return params.v_max;
    }
    else if (t < t_acc)
    {
        return params.a_max * t + get_start_speed();
    }
    else
    {
        return params.v_max - params.da_max * t;
    }
}

void sync_manager::link_child(movement_profiles::generic_ramp *new_child){
childs.push_back(new_child);
}

void sync_manager::synchronize_childs(int sync_time){
    
}