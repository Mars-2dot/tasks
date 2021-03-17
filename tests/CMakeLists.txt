cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

#find_package(GTest REQUIRED)
#if(NOT GTest_FOUND)
include(${CMAKE_SOURCE_DIR}/ExternalProject.cmake)
include(GoogleTest)
#endif()
#find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
enable_testing()

add_executable(tests
	main.cpp
        tests.h
        task_7_33_tests.cpp
        task_13_1_45_tests.cpp
        task_9_48_tests.cpp
        task_11_158_tests.cpp
#	Task_7_33_tests.cpp
	)
target_link_libraries(tests ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
