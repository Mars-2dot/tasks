cmake_minimum_required(VERSION 3.5)

project(task_13_1_45 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include(../3rd/ExternalProjectBoost.cmake)
include(${CMAKE_SOURCE_DIR}/3rd/ExternalProjectBoost.cmake)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
find_package(Boost COMPONENTS filesystem program_options)
add_executable(task_13_1_45 main.cpp cli.cpp cli.h)
include_directories(${Boost_INCLUDE_DIRS})
#set(Boost_LIBRARIES ${Boost_LIBRARIES} boost/src/external_boost/stage/lib/libboost_filesystem-vc142-mt-x64-1_75)
find_library(boostlib NAMES libboost_filesystem-vc142-mt-x64-1_75 PATHES F:/code/C++/tasks/build-task_13_1_45-Desktop_Qt_6_0_3_MSVC2019_64bit-Release/boost/src/external_boost/stage/lib/libboost_filesystem-vc142-mt-x64-1_75)
target_link_libraries(task_13_1_45 ${external_boost} ) #F:/code/C++/tasks/build-task_13_1_45-Desktop_Qt_6_0_3_MSVC2019_64bit-Release/boost/src/external_boost/stage/lib/libboost_filesystem-vc142-mt-x64-1_75
if(Boost_FOUND)
    else()
	    message(Boost not found)
endif()
