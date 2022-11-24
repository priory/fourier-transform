#ifndef PRIORY_FOURIER_TRANSFORM_FAST_IMPL_HPP
#define PRIORY_FOURIER_TRANSFORM_FAST_IMPL_HPP
#include <cmath>

#include "fourier_transform/complex.hpp"

#include "fourier_transform/internal/trig_converters.hpp"

namespace fourier_transform::internal {
    template<typename T>
    static Complex<T> *_fft(Complex<T> *data, int size, int stride, char inverse = -1) {
        if (size == 1)
            return data;

        const int half_size = size / 2;
        const int double_stride = stride * 2;
        auto *result = new Complex<T>[size];
        const T complex = M_PI / half_size;

        Complex<T> *result_even = _fft<T>(data, half_size, double_stride, inverse);
        Complex<T> *result_odd = _fft<T>(data + stride, half_size, double_stride, inverse);

        for (unsigned int k = 0; k < half_size; k++) {
            const Complex<T> p = result_even[k];
            const T angle = complex * k;
            const Complex<T> twiddle = {_cos(angle), inverse * _sin(angle)};
            const Complex<T> q = twiddle * result_odd[k];

            result[k] = p + q;
            result[k + half_size] = p - q;
        }

        return result;
    }
}

#endif //PRIORY_FOURIER_TRANSFORM_FAST_IMPL_HPP
