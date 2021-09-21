cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(monster-fighter)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(monster-fighter ${SOURCES})