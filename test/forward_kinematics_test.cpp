#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include <blaze/Blaze.h>
#include <fmt/core.h>
#include <fmt/core.h>

using blaze::columnVector;
using blaze::DynamicMatrix;
using blaze::DynamicVector;
using blaze::StaticMatrix;
using blaze::StaticVector;

// DynamicMatrix<int> M1( 39UL, 12UL );
// StaticVector<int,12UL,columnVector> v1;

// ... Initialization of the matrix and the vector

// DynamicVector<int,columnVector> v2 = M1 * v1;           // Matrix/column vector multiplication
// DynamicVector<int,rowVector>    v3 = trans( v1 ) * M1;  // Row vector/matrix multiplication

TEST_CASE("SingleStar Estimator in one dimension")
{
    // General Multi-dimensional kalman filter:
    /*
    x_k = A * x_k-1 + b u_k + w_k
    x state matrix [x y z]
    u control variable matrix
    w noise
    */

    double initial_estimate = 68;
    double initial_error = 2;
    double initial_measurement = 75;
    double measurement_error = 4;
 
    std::vector<double> measurements = {68, 75, 71, 70, 74};
    std::vector<double> correct_estimates = {68, 70.3333333333, 70.5, 70.4, 71};
    std::vector<double> correct_kg = {0.33, 0.25, 0.20, 0.17};
    std::vector<double> correct_estimated_errors = {1.33, 1.0, 0.8, 0.66};

    std::vector<double> all_kalman_gains = {0, 0, 0, 0};
    double estimated_error;
    std::vector<double> all_estimated_errors = {initial_error, 0, 0, 0};
    std::vector<double> all_estimates = {initial_estimate, 75, 71, 70, 74};

    std::vector<double> estimates;

    StaticMatrix<double, 1UL, 1UL> A;
    StaticVector<double, 1UL, columnVector> x_kminus1; // < The last estimate
    StaticVector<double, 1UL, columnVector> x_k;       // < The current estimate

    // One Dimensional Matrix:
    StaticMatrix<double, 1UL, 1UL> b; //= {1};
    // We have no control matrix:
    StaticVector<double, 1UL, columnVector> u_k = {0};

    StaticVector<double, 1UL, columnVector> w_k; // Noise

    StaticVector<double, 1UL, columnVector> updated_estimate = A * x_kminus1 + b * u_k + w_k;

    estimated_error = initial_error;

    for (int i = 1; i < 5; i++)
    {
        // Update Loop:
        double kalman_gain = estimated_error / (estimated_error + measurement_error);
//        fmt::print("kg = {:.2f}/({:.2f}+{:.2f})\r\n", estimated_error, estimated_error, measurement_error);
        // Calculate the estimates:
        all_estimates[i] = all_estimates[i - 1] + kalman_gain * (measurements[i] - all_estimates[i - 1]);
//        fmt::print("est = {:.2f}+{:.2f}*[{:.2f}-{:.2f}] = {:.2f}\r\n", all_estimates[i - 1], kalman_gain, measurements[i], all_estimates[i - 1], all_estimates[i]);

        // Update Error:
        estimated_error = (1 - kalman_gain) * all_estimated_errors[i - 1];
        all_estimated_errors[i] = estimated_error;
        all_kalman_gains[i] = kalman_gain;
//        fmt::print("error_est = [1-{:.2f}]*{:.2f}\r\n\n", kalman_gain, all_estimated_errors[i - 1]);
    }

//    CHECK(all_estimates==correct_estimates);
//    REQUIRE_THAT(all_estimated_errors, Catch::Matchers::Equals(correct_estimated_errors));
//    REQUIRE_THAT(all_kalman_gains, Catch::Matchers::Equals(correct_kg));
}