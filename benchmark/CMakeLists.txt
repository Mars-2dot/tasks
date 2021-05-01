cmake_minimum_required(VERSION 3.5)

project(GBenchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../headers)
add_executable(GBenchmark
   BM_Task_7_33.cpp
   BM_Task_11_158.cpp
   benchmark.cpp
   ../headers/benchmark.h
   ../headers/random.h
   ../headers/tasks.h
   ../headers/mylist.h
    )
find_package(benchmark
    PATHS
    ${CMAKE_BINARY_DIR}/dependencies/benchmark/lib/cmake/benchmark
    )

if (benchmark_FOUND)
        message("***benchmark found***")
else()
        message("***benchmark not found***")
        include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ExternalProjectGbenchmark.cmake)
endif()

target_link_libraries(GBenchmark benchmark::benchmark tasks
 Shlwapi)
