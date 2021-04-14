find_package(Threads REQUIRED)
include(ExternalProject)

set(TMP_PATH ${CMAKE_BINARY_DIR}/3rd/external_files/tmp)
set(STAMP_PATH ${CMAKE_BINARY_DIR}/3rd/external_files/stamp)
set(LOG_PATH ${CMAKE_BINARY_DIR}/3rd/external_files/log)

set(GBENCHMARK_ROOT ${CMAKE_BINARY_DIR}/3rd/benchmark)
set(BENCHMARKLIB_PATH ${CMAKE_BINARY_DIR}/3rd/benchmark/src/Debug/benchmark.lib)
set(BENCHMARKLIB_MAIN_PATH ${CMAKE_BINARY_DIR}/3rd/benchmark/src/Debug/benchmark_main.lib)
set(GMOCK_INCLUDE_DIRS ${GBENCHMARK_ROOT}/googlemock/include)
set(GBENCHMARK_INCLUDE_DIRS ${GBENCHMARK_ROOT}/include)
set(BENCMARK_INSTALL_CMAKE ${CMAKE_BINARY_DIR}/dependencies/benchmark)

ExternalProject_Add(googlebenchmark
    PREFIX            ${GBENCHMARK_ROOT}
    DOWNLOAD_DIR      ${GBENCHMARK_ROOT}
    SOURCE_DIR        ${GBENCHMARK_ROOT}
    BINARY_DIR        ${GBENCHMARK_ROOT}
    TMP_DIR           ${TMP_PATH}
    STAMP_DIR         ${STAMP_PATH}
    LOG_DIR 	      ${LOG_PATH}
    GIT_REPOSITORY    https://github.com/google/benchmark.git
    GIT_TAG           master
    CONFIGURE_COMMAND ${CMAKE_COMMAND} -B ${GBENCHMARK_ROOT} -S ${GBENCHMARK_ROOT} -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON
    BUILD_COMMAND     ${CMAKE_COMMAND} --build ${GBENCHMARK_ROOT} --config Debug
    INSTALL_COMMAND   ""
    BUILD_BYPRODUCTS  ${BENCHMARKLIB_PATH}
)

file(MAKE_DIRECTORY ${GBENCHMARK_INCLUDE_DIRS})
file(MAKE_DIRECTORY ${GMOCK_INCLUDE_DIRS})
file(MAKE_DIRECTORY ${BENCMARK_INSTALL_CMAKE})
file(MAKE_DIRECTORY ${BENCMARK_INSTALL_CMAKE}/lib)
file(MAKE_DIRECTORY ${BENCMARK_INSTALL_CMAKE}/lib/pkgconfig)
file(MAKE_DIRECTORY ${BENCMARK_INSTALL_CMAKE}/lib/cmake/benchmark)
file(MAKE_DIRECTORY ${BENCMARK_INSTALL_CMAKE}/include)

if(UNIX)
        set(GBENCHMARK_LIBRARY_PATH ${GBENCHMARK_ROOT}/lib/benchmark.a)
else ()
        set(GBENCHMARK_LIBRARY_PATH ${BENCHMARKLIB_PATH})
endif ()

set(GBENCHMARK_LIBRARY Benchmark)

include_directories(${GBENCHMARK_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

link_directories(${GBENCHMARK_ROOT}/src/Debug)

add_library(benchmark::benchmark UNKNOWN IMPORTED)
set_target_properties(benchmark::benchmark PROPERTIES
    "IMPORTED_LOCATION" "${GBENCHMARK_LIBRARY_PATH}"
    "INCLUDE_DIRECTORIES" "${GBENCHMARK_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GBENCHMARK_INCLUDE_DIRS}"
)
add_dependencies(benchmark::benchmark googlebenchmark)

set(CMAKE_FIND_BENCHMARK_PATH ${CMAKE_BINARY_DIR}/3rd/benchmark/src/CMakeFiles/Export/lib/cmake/benchmark)
set(CMAKE_FIND_BENCHMARK_PATH_CONF ${CMAKE_BINARY_DIR}/3rd/benchmark/src/generated)

list(APPEND CMAKE_FIND_BENCHMARK_FILES
    ${CMAKE_FIND_BENCHMARK_PATH}/benchmarkTargets.cmake
    ${CMAKE_FIND_BENCHMARK_PATH}/benchmarkTargets-debug.cmake
    ${CMAKE_FIND_BENCHMARK_PATH}/benchmarkTargets-minsizerel.cmake
    ${CMAKE_FIND_BENCHMARK_PATH}/benchmarkTargets-release.cmake
    ${CMAKE_FIND_BENCHMARK_PATH}/benchmarkTargets-relwithdebinfo.cmake
    ${CMAKE_FIND_BENCHMARK_PATH_CONF}/benchmarkConfig.cmake
    ${CMAKE_FIND_BENCHMARK_PATH_CONF}/benchmarkConfigVersion.cmake
    )

add_custom_command(
        TARGET googlebenchmark POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_BINARY_DIR}/3rd/benchmark/include
                ${BENCMARK_INSTALL_CMAKE}/include)
add_custom_command(
        TARGET googlebenchmark POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_FIND_BENCHMARK_FILES}
                ${BENCMARK_INSTALL_CMAKE}/lib/cmake/benchmark)
add_custom_command(
        TARGET googlebenchmark POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_FIND_BENCHMARK_PATH_CONF}/benchmark.pc
                ${BENCMARK_INSTALL_CMAKE}/lib/pkgconfig)
add_custom_command(
        TARGET googlebenchmark POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${BENCHMARKLIB_PATH}
                ${BENCHMARKLIB_MAIN_PATH}
                ${BENCMARK_INSTALL_CMAKE}/lib)
