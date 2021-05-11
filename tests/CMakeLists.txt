cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Boost COMPONENTS filesystem program_options
#    PATHS
#    ${CMAKE_SOURCE_DIR}/dependencies/googletest/lib/cmake/GTest
#    )

add_executable(tests
        ../headers/tests.h
        ../headers/tasks.h
        ../headers/mylist.h
        main.cpp
        task_7_33_tests.cpp
        task_13_1_45_tests.cpp
        task_9_48_tests.cpp
        task_11_158_tests.cpp
        )

find_package(GTest
    PATHS
    ${CMAKE_SOURCE_DIR}/dependencies/googletest/lib/cmake/GTest
)

include_directories(${CMAKE_BINARY_DIR}/dependencies/Boost/include)

if(GTest_FOUND)
        message("***GTest found***")
        include_directories(${CMAKE_BINARY_DIR}/dependencies/googletest/include)
else()
        message("***GTest not found***")
        include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ExternalProjectGtests.cmake)
endif()

target_link_libraries(tests GTest::gtest GTest::gtest_main tasks)
