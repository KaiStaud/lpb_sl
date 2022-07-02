#include "../include/forward_kinematics.hpp"
#include "blaze/Math.h"

using namespace forward_kinematics;

SingleStarEstimator::SingleStarEstimator()
{
}

bool SingleStarEstimator::ApplyCheckCube(double d)
{
    distance = sqrt(pow(d, 2) * 2);
}

SimpleProgress SingleStarEstimator::IsStarReached(tstar cmp_star)
{
    blaze::StaticVector<std::int32_t, 3UL> b;
    b[0] = cmp_star.xyz[0];
    b[1] = cmp_star.xyz[1];
    b[2] = cmp_star.xyz[2];
    blaze::StaticVector<std::int32_t, 3UL> set_star;
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

tstar SingleStarEstimator::ApplyCalmanFilter(double x_p, double x_v, double a_x)
{
    blaze::StaticVector<double, 3UL, blaze::columnVector> current_sample;
    current_sample[0] = x_p;
    current_sample[1] = x_v;
    current_sample[2] = a_x;

    blaze::StaticVector<int, 3UL> k_p0 = kalman_gain * (A * current_sample) + ((1 - kalman_gain) * last_statematrix);
}

bool SingleStarEstimator::SetOffsets(std::int32_t b_x, std::int32_t b_y, std::int32_t b_z)
{
    bias[0] = b_x;
    bias[1] = b_y;
    bias[2] = b_z;
}
void SingleStarEstimator::SetKalmanGain(double k_x, double k_y, double k_z)
{
    kalman_gain = k_x;
}
void SingleStarEstimator::SetMatrix(blaze::StaticMatrix<double, 3UL, 3UL> a)
{
    A = a;
}

RequestState SingleStarEstimator::RequestNewStar()
{
}