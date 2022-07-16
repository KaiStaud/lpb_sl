#include "blaze/Math.h"
#include <math.h>
#include <utility>
#include "../include/forward_kinematics.hpp"

using blaze::StaticVector;
using blaze::DynamicVector;

#define PI 3.14159265

// Helper Funktionen:

// Geradengleichung aus Vektor bestimmen:

std::pair<double, double> calculate_vector_fx(double m, StaticVector<double, 3UL> v)
{

    auto b = v[1] - m * v[0];

    auto fx_params = std::make_pair(m, b);

    return fx_params;
}

std::pair<double, double> calculate_vector_fx(StaticVector<double, 3UL> v, StaticVector<double, 3UL> y)
{

    auto m = (v[1] - y[1]) / (v[0] - y[0]);

    auto b = v[1] - m * v[0];

    auto fx_params = std::make_pair(m, b);

    return fx_params;
}

// Schnittpunkt (intersection) von zwei vektoren bestimmen:

StaticVector<double, 3UL> calculate_intersection(double a, double b, double m, double u)
{

    StaticVector<double, 3UL> i;

    i[0] = (u - b) / (a - m);

    i[1] = a * i[0] + b;

    return i;
}

enum class IK_Error
{

    out_of_range = 0,

    ik_solved = 1,

    no_solution_found = 2,

};

// Perform a simple IK: If not set, use preset tuple:

IK_Error simple_ik(double sizeof_arm = 4, double num_effectors = 2, StaticVector<double, 3UL> e_r = {5, 5, 0})
{

    // Instantiation of a static 3D column vector. The vector is directly initialized as

    StaticVector<double, 3UL> a{4, -2, 5};

    // Instantiation of a dynamic 3D column vector. Via the subscript operator the values are set to

    DynamicVector<double> e_2(3UL);

    DynamicVector<double> e_1(3UL);

    e_r[0] = 5;

    e_r[1] = 5;

    e_r[2] = 0;

    // Fehlerfaelle pruefen:

    if (length(e_r) > num_effectors * sizeof_arm)
    {

        return IK_Error::out_of_range;
    }

    else

    {

        // Haelfte vom ZielVektor berechnen:

        auto alpha = atan(e_r[1] / e_r[0]);

//        std::cout << "\r\n Alpha [rad] = " << alpha;

        auto y_stuetzvektor = sin(alpha) * (length(e_r) / 2);

        auto x_stuetzvektor = cos(alpha) * (length(e_r) / 2);
        ;

        // Normalvektor berechnen:

        auto sizeof_n = sqrt(pow(sizeof_arm, 2) - pow(length(e_r) / 2, 2));

        // std::cout << "\r\n Zielvektor-Länge=  = " << length(e_r) / 2;
        // std::cout << "\r\n Normalvektor-Länge=  = " << sizeof_n;

        // Jetzt den Winkel zwischen effektor1 und x Achse berechen

        auto beta = alpha + (sizeof_n / (length(e_r) / 2));

//        std::cout << "\r\n Beta [rad] = " << beta;

        // Koordinaten vom Schnittpunkt des normalenvektors und effektor1:

        e_1[0] = cos(beta) * sizeof_arm;

        e_1[1] = sin(beta) * sizeof_arm;

        // std::cout << "\r\n"
        //           << e_1[0] << " " << e_1[1];

        // Vom Schnittpunkt aus kann der nächste Effektor bestimmt werden:

        auto effektor2 = e_r - e_1;

        // TCP wurde bereits übergeben! Nix mehr zu tun!

        return IK_Error::ik_solved;
    }
}