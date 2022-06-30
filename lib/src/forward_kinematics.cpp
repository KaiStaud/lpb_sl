#include "../include/forward_kinematics.hpp"
#include "blaze/Math.h"

SingleStarEstimator::SingleStarEstimator()
{
}

bool SingleStarEstimator::AddCheckCube(double d)
{
    distance = sqrt(pow(d, 2) * 2);
}

SimpleProgress SingleStarEstimator::IsStarReached(tstar cmp_star)
{
    blaze::DynamicVector<std::int32_t> b(3UL);
    b[0] = cmp_star.xyz[0];
    b[1] = cmp_star.xyz[1];
    b[2] = cmp_star.xyz[2];
    blaze::DynamicVector<std::int32_t> set_star(3UL);
    auto v_dist = set_star - b;
    auto abs_dist = v_dist.size();
    if (abs_dist <= distance)
    {
        return SimpleProgress::reached;
    }
    else
    {
        return SimpleProgress::not_reached;
    }
}

RequestState SingleStarEstimator::RequestNewStar()
{
}