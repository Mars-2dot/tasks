find_package(Threads REQUIRED)

include(ExternalProject)
ExternalProject_Add(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  UPDATE_COMMAND ""
  INSTALL_COMMAND ""
  LOG_DOWNLOAD ON
  LOG_CONFIGURE ON
  LOG_BUILD ON)

ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include)
set(GMOCK_INCLUDE_DIRS ${source_dir}/googlemock/include)

file(MAKE_DIRECTORY ${GTEST_INCLUDE_DIRS})
file(MAKE_DIRECTORY ${GMOCK_INCLUDE_DIRS})

ExternalProject_Get_Property(googletest binary_dir)
if(UNIX)
set(GTEST_LIBRARY_PATH ${binary_dir}/lib/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
else ()
set(GTEST_LIBRARY_PATH ${binary_dir}/lib/${CMAKE_FIND_LIBRARY_PREFIXES}/Debug/gtestd.lib)
endif ()

set(GTEST_LIBRARY gtest)
add_library(${GTEST_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GTEST_LIBRARY} PROPERTIES
    "IMPORTED_LOCATION" "${GTEST_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GTEST_INCLUDE_DIRS}")
add_dependencies(${GTEST_LIBRARY} googletest)
if(UNIX)
set(GTEST_MAIN_LIBRARY_PATH ${binary_dir}/lib/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main.a)
else ()
set(GTEST_MAIN_LIBRARY_PATH ${binary_dir}/lib/${CMAKE_FIND_LIBRARY_PREFIXES}/Debug/gtest_maind.lib)
endif ()

set(GTEST_MAIN_LIBRARY gtest_main)
add_library(${GTEST_MAIN_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GTEST_MAIN_LIBRARY} PROPERTIES
    "IMPORTED_LOCATION" "${GTEST_MAIN_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GTEST_INCLUDE_DIRS}")
add_dependencies(${GTEST_MAIN_LIBRARY} googletest)
if(UNIX)
set(GMOCK_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock.a)
else ()
set(GMOCK_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}/Debug/gmockd.lib)
endif ()

set(GMOCK_LIBRARY gmock)
add_library(${GMOCK_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GMOCK_LIBRARY} PROPERTIES
    "IMPORTED_LOCATION" "${GMOCK_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GMOCK_INCLUDE_DIRS}")
add_dependencies(${GMOCK_LIBRARY} googletest)
if(UNIX)
set(GMOCK_MAIN_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock_main.a)
else ()
set(GMOCK_MAIN_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}/Debug/gmock_maind.lib)
endif ()

set(GMOCK_MAIN_LIBRARY gmock_main)
add_library(${GMOCK_MAIN_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GMOCK_MAIN_LIBRARY} PROPERTIES
    "IMPORTED_LOCATION" "${GMOCK_MAIN_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GMOCK_INCLUDE_DIRS}")
add_dependencies(${GMOCK_MAIN_LIBRARY} ${GTEST_LIBRARY})
