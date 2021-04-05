cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif ()

include(${CMAKE_SOURCE_DIR}/3rd/ExternalProjectGtests.cmake)

include_directories(${GTEST_INCLUDE_DIRS})

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
