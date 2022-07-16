#include <eigen3/Eigen/Dense>
#include <math.h>
#include <utility>

using Eigen::VectorXd;

#define PI 3.14159265


enum class IK_Error
{

    out_of_range = 0,

    ik_solved = 1,

    no_solution_found = 2,

};

// Helper Funktionen:

// Geradengleichung aus Vektor bestimmen:
std::pair<double, double> calculate_vector_fx(double m, Eigen::Vector3d v);
std::pair<double, double> calculate_vector_fx(Eigen::Vector3d v, Eigen::Vector3d y);

// Schnittpunkt (intersection) von zwei vektoren bestimmen:
Eigen::VectorXd calculate_intersection(double a, double b, double m, double u);

// Perform a simple IK: If not set, use preset tuple:
IK_Error simple_ik(double sizeof_arm = 4, double num_effectors = 2, Eigen::VectorXd e_r = {5, 5, 0});
