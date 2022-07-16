#include <iostream>
#include <eigen3/Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class KalmanFilter
{

public:
    void guess_state(VectorXd p_x_hut);
    void load_covariance_matrix(MatrixXd p_p0);
    void load_process_noise_matrix(MatrixXd p_Q);
    void load_observation_matrix(MatrixXd p_H);
    void load_measurement_uncertainty_matrix(MatrixXd p_R);
    void load_state_transistion_matrix(MatrixXd p_F);
    void set_identity_matrix(MatrixXd p_I);
    void set_gain_matrix(MatrixXd p_k);

    void process();
    void initialize();
    void measure();
    VectorXd update( VectorXd z);
    void predict();

private:
   
    VectorXd x_hut;
    VectorXd x_prediction;
    MatrixXd P;
    MatrixXd F;
    MatrixXd Q;
    MatrixXd R;
    MatrixXd H;
    MatrixXd k1;
    MatrixXd I;

};
