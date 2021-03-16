cmake_minimum_required(VERSION 3.5)

project(task_13_1_45 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost COMPONENTS filesystem program_options)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(task_13_1_45 main.cpp cli.cpp cli.h)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(task_13_1_45 ${Boost_LIBRARIES} )
endif()
