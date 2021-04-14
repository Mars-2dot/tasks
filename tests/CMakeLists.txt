cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif ()

find_package(Boost COMPONENTS filesystem program_options
    PATHS
    ${CMAKE_BINARY_DIR}/dependencies/Boost/lib/cmake
    )

add_executable(tests
        ../headers/tests.h
        ../headers/tasks.h
        ../source/task_7_33.cpp
        ../source/task_9_48.cpp
        ../source/task_11_158.cpp
        ../source/Task_13_1_45.cpp
        main.cpp
        task_7_33_tests.cpp
        task_13_1_45_tests.cpp
        task_9_48_tests.cpp
        task_11_158_tests.cpp
        )

find_package(GTest
    PATHS
    ${CMAKE_BINARY_DIR}/dependencies/googletest/lib/cmake/GTest
)

include_directories(${CMAKE_BINARY_DIR}/dependencies/Boost/include)

if(GTest_FOUND)
        message("***GTest found***")
        include_directories(${CMAKE_BINARY_DIR}/dependencies/googletest/include)
else()
        message("***GTest not found***")
        include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ExternalProjectGtests.cmake)
endif()

target_link_libraries(tests GTest::gtest GTest::gtest_main)
