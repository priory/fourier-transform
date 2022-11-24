#ifndef PRIORY_FOURIER_TRANSFORM_COMPLEX_OSTREAM_H
#define PRIORY_FOURIER_TRANSFORM_COMPLEX_OSTREAM_H

#include <iomanip>
#include <iostream>

#include "fourier_transform/complex.hpp"

template<typename T>
std::ostream &operator<<(std::ostream &os, const fourier_transform::Complex<T> &complex) {
    os << std::fixed << std::setprecision(6);
    os << '(' << complex.real << ',' << ' ' << complex.imaginary << ')';
    os << std::scientific;
    return os;
}

#endif //PRIORY_FOURIER_TRANSFORM_COMPLEX_OSTREAM_H
