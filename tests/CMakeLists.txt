cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

find_package(GTest)

include_directories(${CMAKE_BINARY_DIR}/dependencies/Boost/include)

target_link_libraries(tests
    ${GTest_LIBRARIES}
    tasks)
