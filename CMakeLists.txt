cmake_minimum_required(VERSION 3.21)
project(array)

set(CMAKE_CXX_STANDARD 20)

add_executable(array main.cpp Array.cpp Array.h Vector.cpp Vector.h)
