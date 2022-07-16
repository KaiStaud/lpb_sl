#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include "../lib/include/inverse_kinematics.hpp"
#include <eigen3/Eigen/Dense>

using Eigen::Vector3d;
// TEST_CASE("Inverse Kinematik mit zwei Gliedern")
// {

//     Vector3d t1{0, 0, 5};
//     Vector3d t2{5, 5, 5};
//     Vector3d t3{0, 5, 5};
//     Vector3d t4{5, 0, 5};

//     auto res1 = calculate_vector_fx(t1, t2);

//     std::cout << res1.first << " " << res1.second << "\r\n";

//     auto res2 = calculate_vector_fx(t3, t4);

//     std::cout << res2.first << " " << res2.second << "\r\n";

//     auto intersection = calculate_intersection(res1.first, res1.second, res2.first, res2.second);

//     std::cout << intersection[0] << " " << intersection[1];

//     MATCH(2.5,2.5)
//     REQUIRE(simple_ik() == 1);
// }

TEST_CASE("Schnittpunkte von zwei Vektoren")
{

    Vector3d t1{0, 0, 5};
    Vector3d t2{5, 5, 5};
    Vector3d t3{0, 5, 5};
    Vector3d t4{5, 0, 5};

    auto res1 = calculate_vector_fx(t1, t2);

    // std::cout << res1.first << " " << res1.second << "\r\n";

    // auto res2 = calculate_vector_fx(t3, t4);

    // std::cout << res2.first << " " << res2.second << "\r\n";

    // auto intersection = calculate_intersection(res1.first, res1.second, res2.first, res2.second);

    // std::cout << intersection[0] << " " << intersection[1];

    // // MATCH(2.5,2.5)
    // CHECK(res1 == std::make_pair<double, double>(1, 0));
    // CHECK(res2 == std::make_pair<double, double>(-1, 5));
    // // CHECK(intersection==std::make_pair<double,double>(2.5,2.5));
}