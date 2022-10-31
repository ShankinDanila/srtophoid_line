cmake_minimum_required(VERSION 3.20)
project(lib)

set(CMAKE_CXX_STANDARD 14)

add_library(lib Strophoid.cpp Errors.h Strophoid.h)
