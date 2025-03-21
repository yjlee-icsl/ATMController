cmake_minimum_required(VERSION 3.10)
project(atm_controller VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(atm_controller src/main.cpp)