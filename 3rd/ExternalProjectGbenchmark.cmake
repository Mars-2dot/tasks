find_package(Threads REQUIRED)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
include(ExternalProject)
ExternalProject_Add(googlebenchmark
  GIT_REPOSITORY    https://github.com/google/benchmark.git
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-src"
  BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-build"
  CONFIGURE_COMMAND ${CMAKE_COMMAND} -B ${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-build -S ${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-src -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON
  BUILD_COMMAND     ${CMAKE_COMMAND} --build ${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-build --config Debug
  INSTALL_COMMAND   ""
)

ExternalProject_Get_Property(googlebenchmark source_dir)
set(GBENCHMARK_INCLUDE_DIRS ${source_dir}/include)
set(GMOCK_INCLUDE_DIRS ${source_dir}/googlemock/include)

file(MAKE_DIRECTORY ${GBENCHMARK_INCLUDE_DIRS})
file(MAKE_DIRECTORY ${GMOCK_INCLUDE_DIRS})

ExternalProject_Get_Property(googlebenchmark binary_dir)
if(UNIX)
set(GBENCHMARK_LIBRARY_PATH ${binary_dir}/src/${CMAKE_FIND_LIBRARY_PREFIXES}benchmark.a)
else ()
	set(GBENCHMARK_LIBRARY_PATH ${binary_dir}/src/${CMAKE_FIND_LIBRARY_PREFIXES}Debug/benchmark.lib)
endif ()

set(GBENCHMARK_LIBRARY Benchmark)
include_directories(SOURCE_DIR/include)
add_library(${GBENCHMARK_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GBENCHMARK_LIBRARY} PROPERTIES
    "IMPORTED_LOCATION" "${GBENCHMARK_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GBENCHMARK_INCLUDE_DIRS}")
add_dependencies(${GBENCHMARK_LIBRARY} googlebenchmark)
