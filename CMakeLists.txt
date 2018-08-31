cmake_minimum_required(VERSION 3.12)
project(PDZone C)

set(CMAKE_C_STANDARD 99)

add_executable(PDZone main.c IPAddress.cpp)