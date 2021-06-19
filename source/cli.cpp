#include "cli.h"

cli::cli( int argc, char* argv[] )
{
    optionsDescriptions.add_options()
    ( "help", "produce help message" )
    ( "input-file,i",  po::value<std::string>( &inputFilePath )->composing(),
      "set input file path" )
    ( "output-file,o",  po::value<std::string>( &outputFilePath )->composing(),
      "set output file path" )
    ( "search,s", po::value<std::string>( &search ), "word to search" )
    ( "reaplace,r",  po::value<std::string>( &reaplace ), "word to reaplace" );
    po::store( po::parse_command_line( argc, argv, optionsDescriptions ), map );
    po::notify( map );
}

int cli::exec()
{
    if ( map.count( "help" ) ) {
        std::cout << optionsDescriptions << std::endl;
        return 1;
    } else if ( map.size() == 4 && map.count( "search" ) && map.count( "reaplace" ) && map.count( "input-file" ) &&
                map.count( "output-file" ) ) {
        reaplaceText(
            boost::any_cast<std::string>( map["input-file"].value() ),
            boost::any_cast<std::string>( map["output-file"].value() ),
            boost::any_cast<std::string>( map["search"].value() ),
            boost::any_cast<std::string>( map["reaplace"].value() )
        );
        return 0;
    } else {
        std::cout << "Please, use --help option for information" << std::endl;
        return 1;
    }
}
