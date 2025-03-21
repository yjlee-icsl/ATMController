cmake_minimum_required(VERSION 3.10)
project(atm_controller VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DPROJECT_ROOT_PATH="${CMAKE_SOURCE_DIR}")

include_directories(include)

add_executable(atm_controller
    src/card_information.cpp
    src/bank_api.cpp
    src/atm_controller.cpp
    src/main.cpp
)