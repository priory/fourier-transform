cmake_minimum_required(VERSION 3.23)
project(fourier_transform)

set(CMAKE_CXX_STANDARD 14)

if(MSVC)
	add_definitions( -D_USE_MATH_DEFINES )
endif()

add_library(fourier_transform INTERFACE)

target_include_directories(fourier_transform INTERFACE ./include)
