#ifndef PRIORY_FOURIER_TRANSFORM_TRIG_CONVERTERS_HPP
#define PRIORY_FOURIER_TRANSFORM_TRIG_CONVERTERS_HPP

#include <cmath>

namespace fourier_transform::internal {
    double _cos(double X) { return cos(X); };

    float _cos(float X) { return cosf(X); };

    long double _cos(long double X) { return cosl(X); }

    double _sin(double X) { return sin(X); };

    float _sin(float X) { return sinf(X); };

    long double _sin(long double X) { return sinl(X); };
}

#endif //PRIORY_FOURIER_TRANSFORM_TRIG_CONVERTERS_HPP
