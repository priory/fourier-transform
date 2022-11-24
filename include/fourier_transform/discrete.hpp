#ifndef PRIORY_FOURIER_TRANSFORM_DISCRETE_HPP
#define PRIORY_FOURIER_TRANSFORM_DISCRETE_HPP

#include <cmath>

#include "fourier_transform/complex.hpp"

#include "fourier_transform/internal/discrete_impl.hpp"

namespace fourier_transform {
    template<typename T>
    Complex<T> *dft(const Complex<T> *data, int size) {
        return internal::_dft(data, size, -1);
    }

    template<typename T>
    Complex<T> *idft(const Complex<T> *data, int size) {
        return internal::_dft(data, size, 1);
    }
}

#endif //PRIORY_FOURIER_TRANSFORM_DISCRETE_HPP
