#ifndef COLOR_H
#define COLOR_H

#include "interval.h"
#include "vec3.h"

using color = vec3;

inline double linear_to_Gamma(double linear_component)
{
    if (linear_component > 0)
      return std::sqrt(linear_component);

    return 0;
}

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Apply a linear to gamma transform for gamma 2
    r = linear_to_Gamma(r);
    g = linear_to_Gamma(g);
    b = linear_to_Gamma(b);
    

    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity (0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif

// We use double here, but some ray tracers use float. double has greater precision and range, but is twice the size compared to float. This increase in size may be important if you're programming in limited memory conditions (such as hardware shaders).