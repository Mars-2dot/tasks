cmake_minimum_required(VERSION 3.5)

project(GBenchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../headers)

add_executable(GBenchmark
   BM_Task_7_33.cpp
   BM_Task_11_158.cpp
   BM_task_9_48.cpp
   benchmark.cpp
   ../headers/benchmark.h
   ../headers/random.h
   ../headers/tasks.h
   ../headers/mylist.h
   ../headers/generate.h
    )

target_link_libraries(GBenchmark
    "${benchmark_LIBRARIES}"
    tasks
 Shlwapi)
