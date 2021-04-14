find_package(Threads REQUIRED)

include( ExternalProject )

set( boost_URL "https://sourceforge.net/projects/boost/files/boost/1.75.0/boost_1_75_0.tar.bz2" )

set(TMP_PATH ${CMAKE_BINARY_DIR}/3rd/external_files/tmp)
set(STAMP_PATH ${CMAKE_BINARY_DIR}/3rd/external_files/stamp)
set(LOG_PATH ${CMAKE_BINARY_DIR}/3rd/external_files/log)

set( BOOST_ROOT ${CMAKE_BINARY_DIR}/3rd/boost )
set( boost_INSTALL ${CMAKE_BINARY_DIR}/dependencies/Boost )
set( boost_LIB_DIRS ${boost_INSTALL}/lib )
set( Boost_INCLUDE_DIR ${boost_INSTALL}/include/boost-1_75)
set( BOOST_PO_PATH ${boost_LIB_DIRS}/libboost_program_options-vc${MSVC_TOOLSET_VERSION}-mt-gd-x64-1_75.lib)
set( BOOST_FS_PATH ${boost_LIB_DIRS}/libboost_filesystem-vc${MSVC_TOOLSET_VERSION}-mt-gd-x64-1_75.lib )

file(MAKE_DIRECTORY ${Boost_INCLUDE_DIR}/boost/filesystem)
file(MAKE_DIRECTORY ${boost_LIB_DIRS})

ExternalProject_Add( external_boost
        PREFIX 	       ${BOOST_ROOT}
        TMP_DIR        ${TMP_PATH}
        STAMP_DIR      ${STAMP_PATH}
        LOG_DIR        ${LOG_PATH}
        URL            ${boost_URL}
        BUILD_IN_SOURCE 1
        DOWNLOAD_DIR  ${CMAKE_BINARY_DIR}/3rd/boost
        SOURCE_DIR    ${CMAKE_BINARY_DIR}/3rd/boost
        CONFIGURE_COMMAND bootstrap.bat
            --with-libraries=program_options,filesystem
        BUILD_COMMAND
             b2 toolset=msvc address-model=64 link=static variant=debug threading=multi install --prefix=${boost_INSTALL}
        UPDATE_COMMAND ""
        INSTALL_COMMAND ""
        LOG_DOWNLOAD ON
        LOG_CONFIGURE ON
        LOG_BUILD ON
        BUILD_BYPRODUCTS ${BOOST_PO_PATH}
        BUILD_BYPRODUCTS ${BOOST_FS_PATH}
        BUILD_BYPRODUCTS ${Boost_INCLUDE_DIR}/boost/filesystem/fstream.hpp
        BUILD_BYPRODUCTS ${Boost_INCLUDE_DIR}/boost/program_options.hpp
        )

include_directories(${Boost_INCLUDE_DIR})
link_directories(${boost_LIB_DIRS})

set(Boost::program_options boost)
add_library( Boost::program_options UNKNOWN IMPORTED )
set_property( TARGET Boost::program_options PROPERTY IMPORTED_LOCATION ${BOOST_PO_PATH}  )
set_property( TARGET Boost::program_options PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR} )
add_dependencies( Boost::program_options  external_boost )

set(Boost::filesystem boost)
add_library( Boost::filesystem UNKNOWN IMPORTED )
set_property( TARGET Boost::filesystem PROPERTY IMPORTED_LOCATION ${BOOST_FS_PATH}  )
set_property( TARGET Boost::filesystem PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR} )
add_dependencies( Boost::filesystem external_boost )
