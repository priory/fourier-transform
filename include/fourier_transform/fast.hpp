#ifndef PRIORY_FOURIER_TRANSFORM_FAST_HPP
#define PRIORY_FOURIER_TRANSFORM_FAST_HPP

#include <cmath>

#include "fourier_transform/complex.hpp"

#include "fourier_transform/internal/fast_impl.hpp"

namespace fourier_transform {
    template<typename T>
    Complex<T> *fft(Complex<T> *data, int size) {
        return internal::_fft<T>(data, size, 1, -1);
    }

    template<typename T>
    Complex<T> *ifft(Complex<T> *data, int size) {
        auto *result = internal::_fft<T>(data, size, 1, 1);

        for (int k = 0; k < size; k++)
            result[k] = result[k] / size;

        return result;
    }
}

#endif //PRIORY_FOURIER_TRANSFORM_FAST_HPP
