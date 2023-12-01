cmake_minimum_required(VERSION 3.10)
project(advent_of_code_2023_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_executable(hello hello.cpp)
add_executable(day1_part1 day1/day1_part1.cpp)
add_executable(day1_part2 day1/day1_part2.cpp)
