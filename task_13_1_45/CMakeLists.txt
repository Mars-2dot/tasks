cmake_minimum_required(VERSION 3.5)

project(task_13_1_45 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(Boost COMPONENTS filesystem program_options)

if(Boost_FOUND)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
add_executable(task_13_1_45 main.cpp cli.cpp cli.h)
target_link_libraries(task_13_1_45 LINK_PUBLIC ${Boost_LIBRARIES} ) 
else()
include(${CMAKE_SOURCE_DIR}/3rd/ExternalProjectBoost.cmake)
include_directories(${Boost_INCLUDE_DIRS})
find_library(boostlib NAMES libboost_filesystem-vc142-mt-x64-1_75 )
add_executable(task_13_1_45 main.cpp cli.cpp cli.h)
target_link_libraries(task_13_1_45 ${external_boost} ) 
endif()
