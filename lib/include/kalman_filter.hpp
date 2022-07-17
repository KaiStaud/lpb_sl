/**
 * @file kalman_filter.hpp
 * @author Kai Staud
 * @brief State Estimator based on Kalman Filter.
 * @version 0.1
 * @date 2022-07-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <eigen3/Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::VectorXd;

class KalmanFilter
{

public:
    void guess_state(VectorXd p_x_hut); //< Initial state, a raw guess
    void load_covariance_matrix(MatrixXd p_p0);
    void load_process_noise_matrix(MatrixXd p_Q);
    void load_observation_matrix(MatrixXd p_H);
    void load_measurement_uncertainty_matrix(MatrixXd p_R);
    void load_state_transistion_matrix(MatrixXd p_F);
    void set_identity_matrix(MatrixXd p_I);
    void set_gain_matrix(MatrixXd p_k);

    void initialize(); //< Initialize Filter after all Matrices are loaded.
    Eigen::VectorXd update( VectorXd z); // Estimate the new state based on measurement z
    void predict(); // Predict next state after update

private:
   
    VectorXd x_hut; //< The new state estimate
    MatrixXd P;
    MatrixXd F;
    MatrixXd Q;
    MatrixXd R;
    MatrixXd H;
    MatrixXd k1;
    MatrixXd I;

};