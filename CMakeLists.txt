cmake_minimum_required(VERSION 3.5)

project(Tasks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(headers)

add_subdirectory(source)
add_subdirectory(benchmark)
add_subdirectory(tests)
