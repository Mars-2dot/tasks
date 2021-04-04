cmake_minimum_required(VERSION 3.5)

project(benchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "/MD")
set(CMAKE_CXX_FLAGS_DEBUG "/MDd")

#set(BENCHMARK_PROJECT_LOCATION ../3rd/benchmark)
include(${CMAKE_CURRENT_SOURCE_DIR}/../3rd/ExternalProjectGbenchmark.cmake)
message("***************************************************************")
add_executable(benchmark
   BM_task_16_8.cpp
   BM_Task_7_33.cpp
   BM_Task_11_158.cpp
   BM_task_9_48.cpp
task_9_48.cpp
Task_11_158.cpp
   quickSort.cpp
   benchmark.cpp
   benchmark.h
   random.h
    )

target_link_libraries(benchmark ${GBENCHMARK_LIBRARY})
