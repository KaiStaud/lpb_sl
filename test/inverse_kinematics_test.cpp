#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include "../lib/include/inverse_kinematics.hpp"
#include <eigen3/Eigen/Dense>

using Eigen::Vector3d;
TEST_CASE("Inverse Kinematik mit zwei Gliedern")
{

    Vector3d t1{0, 0, 5};
    Vector3d t2{5, 5, 5};
    Vector3d t3{0, 5, 5};
    Vector3d t4{5, 0, 5};

    auto res1 = calculate_vector_fx(t1, t2);

    INFO(res1.first << " " << res1.second << "\r\n");

    auto res2 = calculate_vector_fx(t3, t4);

    INFO(res2.first << " " << res2.second << "\r\n");

    auto intersection = calculate_intersection(res1.first, res1.second, res2.first, res2.second);

    INFO(intersection[0] << " " << intersection[1]);
    CHECK(simple_ik(4, 2, Vector3d(5, 5, 0)) == IK_Error::ik_solved);
}

TEST_CASE("Schnittpunkte von zwei Vektoren")
{

    Vector3d t1{0, 0, 5};
    Vector3d t2{5, 5, 5};
    Vector3d t3{0, 5, 5};
    Vector3d t4{5, 0, 5};

    auto res1 = calculate_vector_fx(t1, t2);

    INFO(res1.first << " " << res1.second << "\r\n");

    auto res2 = calculate_vector_fx(t3, t4);

    INFO(res2.first << " " << res2.second << "\r\n");

    auto intersection = calculate_intersection(res1.first, res1.second, res2.first, res2.second);

    INFO(intersection[0] << " " << intersection[1]);

    CHECK(res1 == std::make_pair<double, double>(1, 0));
    CHECK(res2 == std::make_pair<double, double>(-1, 5));
    CHECK(intersection == Eigen::Vector3d(2.5, 2.5, 0));
}