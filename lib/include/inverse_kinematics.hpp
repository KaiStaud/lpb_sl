#include "blaze/Math.h"
#include <math.h>
#include <utility>

using blaze::StaticVector;
using blaze::DynamicVector;

#define PI 3.14159265


enum class IK_Error
{

    out_of_range = 0,

    ik_solved = 1,

    no_solution_found = 2,

};

// Helper Funktionen:

// Geradengleichung aus Vektor bestimmen:
std::pair<double, double> calculate_vector_fx(double m, StaticVector<double, 3UL> v);
std::pair<double, double> calculate_vector_fx(StaticVector<double, 3UL> v, StaticVector<double, 3UL> y);

// Schnittpunkt (intersection) von zwei vektoren bestimmen:
StaticVector<double, 3UL> calculate_intersection(double a, double b, double m, double u);

// Perform a simple IK: If not set, use preset tuple:
IK_Error simple_ik(double sizeof_arm = 4, double num_effectors = 2, StaticVector<double, 3UL> e_r = {5, 5, 0});
