include( ExternalProject )

set( boost_URL "https://sourceforge.net/projects/boost/files/boost/1.75.0/boost_1_75_0.tar.bz2" )
set( boost_SHA1 "6109efd3bdd8b9220d7d85b5e125f7f28721b9a9" )
set( boost_INSTALL ${CMAKE_CURRENT_BINARY_DIR}/3rd_part )
set( boost_INCLUDE_DIRS ${boost_INSTALL}/include)
set( boost_LIB_DIR ${boost_INSTALL}/libs )
set( BOOST_ROOT ${CMAKE_CURRENT_BINARY_DIR}/boost/src/external_boost )
set (EXTRA_CMAKE_ARGS)
list (APPEND EXTRA_CMAKE_ARGS
  -DBoost_NO_SYSTEM_PATHS=ON)

ExternalProject_Add( external_boost
        PREFIX boost
        URL ${boost_URL}
        URL_HASH SHA1=${boost_SHA1}
        BUILD_IN_SOURCE 1
        CONFIGURE_COMMAND bootstrap.bat
            --with-libraries=program_options 
	    --with-libraries=filesystem 
	        BUILD_COMMAND
	     b2 toolset=msvc --address-model=64 --link=static --variant=release stage install 
        INSTALL_COMMAND ""
	)
set( boost_LIBRARY_SUFFIX .lib )
include_directories(${CMAKE_CURRENT_BINARY_DIR}/boost/src/external_boost) 
link_directories(${CMAKE_CURRENT_BINARY_DIR}/boost/src/external_boost/stage/lib)

add_library( boost::program_options  STATIC IMPORTED )
set_property( TARGET boost::program_options PROPERTY IMPORTED_LOCATION ${boost_LIB_DIR}/libboost_program_options.lib )
set_property( TARGET boost::program_options PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${boost_INCLUDE_DIRS} )
add_dependencies( boost::program_options  external_boost )

add_library( boost::filesystem   STATIC IMPORTED )
set_property( TARGET boost::filesystem  PROPERTY IMPORTED_LOCATION ${boost_LIB_DIR}/libboost_filesystem.lib )
set_property( TARGET boost::filesystem PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${boost_INCLUDE_DIRS} )
add_dependencies( boost::filesystem  external_boost )

