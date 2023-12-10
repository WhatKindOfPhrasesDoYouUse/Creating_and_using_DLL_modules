cmake_minimum_required(VERSION 3.26)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_library(static lib/StaticLib.cpp lib/StaticLib.h)
add_library(dynamic dll/DynamicLib.cpp dll/DynamicLib.h)

add_executable(lab3 main.cpp
        lib/StaticLib.cpp
        lib/StaticLib.h
        dll/DynamicLib.cpp
        dll/DynamicLib.h)
