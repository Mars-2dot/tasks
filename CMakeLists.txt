cmake_minimum_required(VERSION 3.5)

project(Tasks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES
    boost/1.76.0
    benchmark/1.5.3
    gtest/cci.20210126
    GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conan-center
                    SETTINGS ${settings})


find_package(boost)
find_package(benchmark)
find_package(GTest)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${benchmark_INCLUDE_DIRS})
include_directories(${GTest_INCLUDE_DIRS})
include_directories(../headers)

include_directories(headers)

add_subdirectory(source)
add_subdirectory(benchmark)
add_subdirectory(tests)
