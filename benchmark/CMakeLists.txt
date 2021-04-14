cmake_minimum_required(VERSION 3.5)

project(GBenchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lshlwapi")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lshlwapi")
        set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS} -lshlwapi")
        set(CMAKE_CXX_FLAGS_RELEASE "/MD")
        set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
endif ()

include_directories(../headers)
add_executable(GBenchmark
   BM_Task_7_33.cpp
   BM_Task_11_158.cpp
   BM_task_9_48.cpp
   benchmark.cpp
   ../source/Task_11_158.cpp
   ../source/Task_7_33.cpp
   ../source/Task_9_48.cpp
   ../headers/benchmark.h
   ../headers/random.h
   ../headers/tasks.h
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

target_link_libraries(GBenchmark benchmark::benchmark
 Shlwapi)
