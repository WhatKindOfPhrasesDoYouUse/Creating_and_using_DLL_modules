cmake_minimum_required(VERSION 3.26)
project(libs)

set(CMAKE_CXX_STANDARD 17)

add_library(StaticLib SHARED lib/StaticLib.cpp lib/StaticLib.h)

add_library(DynamicLib SHARED dll/DynamicLib.cpp dll/DynamicLib.h)

add_executable(libs main.cpp)

target_link_libraries(libs PRIVATE StaticLib DynamicLib ws2_32)
