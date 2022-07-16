// 010-TestCase.cpp
// And write tests in the same file:
#include <catch2/catch_test_macros.hpp>
#include "../lib/include/kalman_filter.hpp"
#include "eigen3/Eigen/Dense"
using Eigen::MatrixXd;
using Eigen::VectorXd;
TEST_CASE("Kalman Filter")
{
    KalmanFilter kfilter;
    // Messwerte
    double messwert_x[] = {-393.66, -375.93, -351.04, -328.96, -299.35, -273.36, -245.89, -222.58, -198.03, -174.17, -146.32, -123.72, -103.47, -78.23, -52.63, -23.34, 25.96, 49.72, 76.94, 95.38, 119.83, 144.01, 161.84, 180.56, 201.42, 222.62, 239.4, 252.51, 266.26, 271.75, 277.4, 294.12, 301.23, 291.8, 299.89};
    double messwert_y[] = {300.4, 301.78, 295.1, 305.19, 301.06, 302.05, 300, 303.57, 296.33, 297.65, 297.41, 299.61, 299.6, 302.39, 295.04, 300.09, 294.72, 298.61, 294.64, 284.88, 272.82, 264.93, 251.46, 241.27, 222.98, 203.73, 184.1, 166.12, 138.71, 119.71, 100.41, 79.76, 50.62, 32.99, 2.14};

    VectorXd x_hut(6);
    VectorXd x_prediction(6);

    MatrixXd P(6UL, 6UL);
    P(0, 0) = 500;
    P(1, 1) = 500;
    P(2, 2) = 500;
    P(3, 3) = 500;
    P(4, 4) = 500;
    P(5, 5) = 500;

    MatrixXd F(6UL, 6UL);F.setIdentity();
    F(0, 1) = F(1, 2) = F(3, 4) = F(4, 5) = 1;
    F(0, 2) = F(3, 5) = 0.5;

    MatrixXd Q(6UL, 6UL);Q.setIdentity();
    Q(0, 1) = Q(0, 2) = Q(1, 0) = Q(2, 1) = Q(3, 4) = Q(3, 5) = Q(4, 3) = Q(5, 3) = 1;
    Q(2, 1) = Q(1, 2) = Q(4, 5) = Q(5, 4) = 1;
    Q = Q * pow(0.2, 2);

    MatrixXd P2(6UL, 6UL);
    kfilter.guess_state(x_hut);
    kfilter.load_state_transistion_matrix(F);
    kfilter.load_process_noise_matrix(Q);
    kfilter.load_covariance_matrix(P);
    kfilter.predict();

    P2 = F * P * F.transpose() + Q;

    MatrixXd R(2UL, 2UL);

    R(0, 0) = R(1, 1) = 9;

    MatrixXd H(2UL, 6UL);

    H(0, 0) = H(1, 3) = 1;

    kfilter.load_measurement_uncertainty_matrix(R);
    kfilter.load_observation_matrix(H);

    /* MEASURE */
    // Messwerte abholen

    VectorXd z1(2UL); //{messwert_x[0],messwert_y[0]};

    z1[0] = messwert_x[0];
    z1[1] = messwert_y[0];

    /* UPDATE */
    MatrixXd k1(6UL, 2UL);
    const int size = 6;
    MatrixXd I(size, size);
    I.setIdentity();
    kfilter.set_gain_matrix(k1);
    kfilter.set_identity_matrix(I);
    kfilter.update(z1);
    
    // Generate Testvalues!
    k1 = P2 * H.transpose() * (H * P2 * H.transpose() + R).inverse();
    x_hut = x_hut+k1*(z1-H*x_hut);
    P2 = (I - k1 * H) * P2 * (I - k1 * H).transpose() + k1 * R * k1.transpose();
    // 
    
    /* PREDICT */
    x_prediction = F * x_hut;
    P2 = F * P2 * F.transpose() + Q;
    kfilter.predict();
    z1[0] = messwert_x[1];
    z1[1] = messwert_y[1];
    kfilter.update(z1);
    // Iterate over measurements:
    CHECK(kfilter.update(z1)==x_hut);
}