#ifndef PRIORY_FOURIER_TRANSFORM_COMPLEX_HPP
#define PRIORY_FOURIER_TRANSFORM_COMPLEX_HPP

namespace fourier_transform {
    template<typename T>
    struct Complex {
        T real;
        T imaginary;

        Complex<T> operator+(const Complex<T> &obj) const;

        Complex<T> &operator+=(const Complex<T> &obj);

        Complex<T> operator-(const Complex<T> &obj) const;

        Complex<T> &operator-=(const Complex<T> &obj);

        Complex<T> operator*(const Complex<T> &obj) const;

        Complex<T> &operator*=(const Complex<T> &obj);

        Complex<T> operator/(const int &right) const;
    };

    template<typename T>
    Complex<T> Complex<T>::operator+(const Complex<T> &obj) const {
        Complex<T> result{};
        result.real = real + obj.real;
        result.imaginary = imaginary + obj.imaginary;
        return result;
    }

    template<typename T>
    Complex<T> &Complex<T>::operator+=(const Complex<T> &obj) {
        *this = *this + obj;
        return *this;
    }

    template<typename T>
    Complex<T> Complex<T>::operator-(const Complex<T> &obj) const {
        Complex<T> result{};
        result.real = real - obj.real;
        result.imaginary = imaginary - obj.imaginary;
        return result;
    }

    template<typename T>
    Complex<T> &Complex<T>::operator-=(const Complex<T> &obj) {
        *this = *this - obj;
        return *this;
    }

    template<typename T>
    Complex<T> Complex<T>::operator*(const Complex<T> &obj) const {
        Complex<T> result{};
        result.real = real * obj.real - imaginary * obj.imaginary;
        result.imaginary = real * obj.imaginary + imaginary * obj.real;
        return result;
    }

    template<typename T>
    Complex<T> &Complex<T>::operator*=(const Complex<T> &obj) {
        *this = *this * obj;
        return *this;
    }

    template<typename T>
    Complex<T> Complex<T>::operator/(const int &right) const {
        Complex result{};
        result.real = real / right;
        result.imaginary = imaginary / right;
        return result;
    }
}

#endif //PRIORY_FOURIER_TRANSFORM_COMPLEX_HPP
