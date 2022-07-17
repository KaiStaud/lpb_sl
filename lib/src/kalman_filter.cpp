#include "../include/kalman_filter.hpp"
void KalmanFilter::load_state_transistion_matrix(MatrixXd p_F)
{
    F = p_F;
}

void KalmanFilter::guess_state(VectorXd p_x_hut)
{
    x_hut = p_x_hut;
}

void KalmanFilter::load_covariance_matrix(MatrixXd p_p0)
{
    P = p_p0;
}
void KalmanFilter::load_process_noise_matrix(MatrixXd p_Q)
{
    Q = p_Q;
}
void KalmanFilter::load_observation_matrix(MatrixXd p_H)
{
    H = p_H;
}
void KalmanFilter::load_measurement_uncertainty_matrix(MatrixXd p_R)
{
    R = p_R;
}
void KalmanFilter::set_identity_matrix(MatrixXd p_I)
{
    I = p_I.setIdentity();
}
void KalmanFilter::set_gain_matrix(MatrixXd p_k)
{
    k1 = p_k;
}

void KalmanFilter::initialize()
{
    P = F * P * F.transpose() + Q;
}
Eigen::VectorXd KalmanFilter::update(VectorXd z)
{
    k1 = P * H.transpose() * (H * P * H.transpose() + R).inverse();
    x_hut = x_hut + k1 * (z - H * x_hut);
    P = (I - k1 * H) * P * (I - k1 * H).transpose() + k1 * R * k1.transpose();
    return x_hut;
}
void KalmanFilter::predict()
{
    x_hut = F * x_hut;
    P = F * P * F.transpose() + Q;
}
