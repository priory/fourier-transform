Fourier Transform
==========================================
A simple fourier transform template library for educational purposes.
### Features
* Discrete fourier transform
* Fast fourier transform
### Installation
Drag the `fourier_transform` into your own `include` folder.

Include the library into your own project:
```cmake
cmake_minimum_required(VERSION 3.23)
project(example)

set(CMAKE_CXX_STANDARD 20)

if(MSVC)
	add_definitions( -D_USE_MATH_DEFINES )
endif()

add_library(fourier_transform INTERFACE)

target_include_directories(fourier_transform INTERFACE ./include)

add_executable(example main.cpp)
target_include_directories(example PRIVATE include)
```
### Usage
Create an array of `Complex<T>` numberes and pass it to a fourier transform:
```c++
#include <iostream>

#include "fourier_transform/fourier_transform.hpp"

using fourier_transform::Complex;

int main() {
    const int sampleSize = 2048;
    Complex<double> data[sampleSize];

    for (int i = 0; i < sampleSize; i++)
        data[i] = {static_cast<double>(i), static_cast<double>(i)};

    std::cout << "===" << std::endl;

    Complex<double> *cycles;
    cycles = fourier_transform::fft<double>(data, sampleSize);

    for (int i = sampleSize - 5; i < sampleSize; i++)
        std::cout << cycles[i] << std::endl;


    Complex<double> *result;
    result = fourier_transform::ifft<double>(cycles, sampleSize);

    for (int i = sampleSize - 5; i < sampleSize; i++)
        std::cout << result[i] << std::endl;
}
```
