#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

#include <random>

//C++ Std Usings

using std::make_shared;
using std::shared_ptr;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Funcions 

inline double degrees_to_radians( double degrees) {
    return degrees * pi / 180.0;
}

// inline double random_double() {
//     // Return a ramdom real in [0,1);
//     return std::rand() / (RAND_MAX + 1.0);
// }

inline double random_double() { //Using <random> from C++. A ver acima em teoria é a implementação em C puro.
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}


inline double random_double(double min, double max) {
    // Return a ramdom real in [min, max).
    return min + (max-min)*random_double();
}

// Comom Headers 

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif