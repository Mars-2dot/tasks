find_package(Threads REQUIRED)

include(ExternalProject)

set(TMP_PATH ${CMAKE_BINARY_DIR}/3rd/external_files/tmp)
set(STAMP_PATH ${CMAKE_BINARY_DIR}/3rd/external_files/stamp)
set(LOG_PATH ${CMAKE_BINARY_DIR}/3rd/external_files/log)

set(GTEST_ROOT ${CMAKE_BINARY_DIR}/3rd/googletest)
set(GTEST_INCLUDE_DIR ${GTEST_ROOT}/googletest/include)
set(GMOCK_INCLUDE ${GTEST_ROOT}/googlemock/include)

set(GTEST_INSTALL_CMAKE ${CMAKE_SOURCE_DIR}/dependencies/googletest)
set(GTEST_LIB ${GTEST_INSTALL_CMAKE}/lib/gtestd.lib)
set(GTEST_LIB_MAIN ${GTEST_INSTALL_CMAKE}/lib/gtest_maind.lib)
set(GMOCK_LIB ${GTEST_INSTALL_CMAKE}/lib/gmockd.lib)
set(GMOCK_LIB_MAIN ${GTEST_INSTALL_CMAKE}/lib/gmock_maind.lib)

ExternalProject_Add( googletest
    PREFIX            ${GTEST_ROOT}
    DOWNLOAD_DIR      ${GTEST_ROOT}
    SOURCE_DIR        ${GTEST_ROOT}
    BINARY_DIR        ${GTEST_ROOT}
    TMP_DIR           ${TMP_PATH}
    STAMP_DIR         ${STAMP_PATH}
    LOG_DIR 	      ${LOG_PATH}
    GIT_REPOSITORY    https://github.com/google/googletest.git
    CMAKE_ARGS        "-Dgtest_force_shared_crt=ON"
    BUILD_COMMAND     ${CMAKE_COMMAND} --build ${GTEST_ROOT} --config Release
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
    BUILD_BYPRODUCTS ${GTEST_LIB}
    BUILD_BYPRODUCTS ${GTEST_LIB_MAIN}
    BUILD_BYPRODUCTS ${GMOCK_LIB}
    BUILD_BYPRODUCTS ${GMOCK_LIB_MAIN}
  )

file(MAKE_DIRECTORY ${GTEST_INCLUDE_DIR})
file(MAKE_DIRECTORY ${GMOCK_INCLUDE})

include_directories(${GTEST_INCLUDE_DIR})

set(GTEST_LIBRARY_DEBUG GTest)
add_library(GTest::gtest UNKNOWN IMPORTED)
set_property( TARGET GTest::gtest PROPERTY IMPORTED_LOCATION  ${GTEST_LIB} )
set_property( TARGET GTest::gtest PROPERTY INCLUDE_DIRECTORIES  ${GTEST_INCLUDE_DIR} )
set_property( TARGET GTest::gtest PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT} )
set_property( TARGET GTest::gtest PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS} )
add_dependencies(GTest::gtest googletest)

set(GTEST_LIBRARY_MAIN_DEBUG GTest_main)
add_library(GTest::gtest_main UNKNOWN IMPORTED)
set_property( TARGET GTest::gtest_main PROPERTY IMPORTED_LOCATION  ${GTEST_LIB_MAIN} )
set_property( TARGET GTest::gtest_main PROPERTY INCLUDE_DIRECTORIES  ${GTEST_INCLUDE_DIR} )
set_property( TARGET GTest::gtest_main PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT} )
set_property( TARGET GTest::gtest_main PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS} )
add_dependencies(GTest::gtest_main googletest)

set(GMOCK_LIBRARY_DEBUG GMock)
add_library(${GMOCK_LIBRARY_DEBUG} UNKNOWN IMPORTED)
set_property( TARGET ${GMOCK_LIBRARY_DEBUG} PROPERTY IMPORTED_LOCATION  ${GMOCK_LIB} )
set_property( TARGET ${GMOCK_LIBRARY_DEBUG} PROPERTY INCLUDE_DIRECTORIES  ${GTEST_INCLUDE_DIR} )
set_property( TARGET ${GMOCK_LIBRARY_DEBUG} PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT} )
set_property( TARGET ${GMOCK_LIBRARY_DEBUG} PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS} )
add_dependencies(${GMOCK_LIBRARY_DEBUG} googletest)

set(GMOCK_LIBRARY_MAIN_DEBUG GMock_main)
add_library(${GMOCK_LIBRARY_MAIN_DEBUG} UNKNOWN IMPORTED)
set_property( TARGET ${GMOCK_LIBRARY_MAIN_DEBUG} PROPERTY IMPORTED_LOCATION  ${GMOCK_LIB_MAIN} )
set_property( TARGET ${GMOCK_LIBRARY_MAIN_DEBUG} PROPERTY INCLUDE_DIRECTORIES  ${GTEST_INCLUDE_DIR} )
set_property( TARGET ${GMOCK_LIBRARY_MAIN_DEBUG} PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT} )
set_property( TARGET ${GMOCK_LIBRARY_MAIN_DEBUG} PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS} )
add_dependencies(${GMOCK_LIBRARY_MAIN_DEBUG} googletest)

set(GTEST_INSTALL_CMAKE_INCLUDE ${GTEST_INSTALL_CMAKE}/include)
set(GTEST_INSTALL_CMAKE_LIB ${GTEST_INSTALL_CMAKE}/lib)
set(GTEST_INSTALL_CMAKE_FIND ${GTEST_INSTALL_CMAKE}/lib/cmake)
set(GTEST_INSTALL_CMAKE_PKGCNF ${GTEST_INSTALL_CMAKE}/lib/pkgconfig)

file(MAKE_DIRECTORY ${GTEST_INSTALL_CMAKE})
file(MAKE_DIRECTORY ${GTEST_INSTALL_CMAKE_INCLUDE})
file(MAKE_DIRECTORY ${GTEST_INSTALL_CMAKE_LIB})
file(MAKE_DIRECTORY ${GTEST_INSTALL_CMAKE_FIND})
file(MAKE_DIRECTORY ${GTEST_INSTALL_CMAKE_PKGCNF})

add_custom_command(
        TARGET googletest POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_BINARY_DIR}/3rd/googletest/googletest/include
                ${GTEST_INSTALL_CMAKE}/include)
add_custom_command(
        TARGET googletest POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_BINARY_DIR}/3rd/googletest/lib
                ${GTEST_INSTALL_CMAKE}/lib)
add_custom_command(
        TARGET googletest POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_BINARY_DIR}/3rd/googletest/googletest/CMakeFiles/Export/lib/cmake
                ${GTEST_INSTALL_CMAKE}/lib/cmake)
add_custom_command(
        TARGET googletest POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/3rd/googletest/googletest/generated/GTestConfig.cmake
                ${CMAKE_BINARY_DIR}/3rd/googletest/googletest/generated/GTestConfigVersion.cmake
                ${GTEST_INSTALL_CMAKE}/lib/cmake/GTest)
add_custom_command(
        TARGET googletest POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/3rd/googletest/googletest/generated/gtest.pc
                ${CMAKE_BINARY_DIR}/3rd/googletest/googletest/generated/gtest_main.pc
                ${GTEST_INSTALL_CMAKE}/lib/pkgconfig)
