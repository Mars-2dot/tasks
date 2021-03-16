cmake_minimum_required(VERSION 3.5)

project(benchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(benchmark REQUIRED)

add_executable(benchmark
   BM_task_16_8.cpp
   BM_Task_7_33.cpp
   BM_Task_11_158.cpp
   BM_task_9_48.cpp
   quickSort.cpp
   benchmark.cpp
   benchmark.h
    )

target_link_libraries(benchmark benchmark::benchmark)
