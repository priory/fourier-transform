#ifndef PRIORY_FOURIER_TRANSFORM_DISCRETE_IMPL_H
#define PRIORY_FOURIER_TRANSFORM_DISCRETE_IMPL_H
#include <cmath>

#include "fourier_transform/complex.hpp"

#include "fourier_transform/internal/trig_converters.hpp"

namespace fourier_transform::internal {
    template<typename T>
    Complex<T> *_dft(const Complex<T> *data, int size, char inverse = -1) {
        auto *result = new Complex<T>[size];
        const T complex = 2 * M_PI / size;
        const int div = inverse == -1 ? 1 : size;

        for (int k = 0; k < size; k++) {
            Complex<T> cycle{0, 0};
            const T complex_k = complex * k;

            for (int n = 0; n < size; n++) {
                const T angle = complex_k * n;
                const Complex<T> exponent{internal::_cos(angle), inverse * internal::_sin(angle)};
                cycle += data[n] * exponent;
            }

            result[k] = cycle / div;
        }

        return result;
    }
}

#endif //PRIORY_FOURIER_TRANSFORM_DISCRETE_IMPL_H
