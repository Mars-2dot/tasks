project(AllTask LANGUAGES CXX)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../headers)

add_executable(tasks_7_33
    Task_7_33.cpp
    Task_7_33_main.cpp
    ../headers/random.h
    )

add_executable(task_9_48 Task_9_48.cpp Task_9_48_main.cpp ../headers/tasks.h)
add_executable(task_11_158 Task_11_158.cpp Task_11_158_main.cpp ../headers/tasks.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(Boost COMPONENTS filesystem program_options
    PATHS
    ${CMAKE_BINARY_DIR}/dependencies/Boost/lib/cmake
    )

if (Boost_FOUND)
        message("***Boost found***")
else()
        message("***Boost not found***")
        include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ExternalProjectBoost.cmake)
endif()

add_executable(task_13_1_45 ../headers/cli.h Task_13_1_45_main.cpp Task_13_1_45.cpp  cli.cpp )

include_directories( ${Boost_INCLUDE_DIR})

target_link_libraries(task_13_1_45 Boost::program_options  Boost::filesystem)


