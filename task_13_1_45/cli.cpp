#include "cli.h"

cli::cli( int argc, char* argv[] )
{
    optionsDescriptions.add_options()
    ( "help", "produce help message" )
    ( "input-file,f",  po::value<std::string>( &inputFilePath )->composing(),
      "set input file path" )
    ( "search,s", po::value<std::string>( &search ), "word to search" )
    ( "reaplace,r",  po::value<std::string>( &reaplace ), "word to reaplace" )
    ;
    po::store( po::parse_command_line( argc, argv, optionsDescriptions ), map );
    po::notify( map );
}

int cli::exec()
{
    if ( map.count( "help" ) ) {
        std::cout << optionsDescriptions << std::endl;
        return 1;
    } else if ( map.size() == 3 && map.count( "search" ) && map.count( "reaplace" ) && map.count( "input-file" ) ) {
        std::string parametrs[3];

        for ( const auto& option : map ) {
            auto& value = option.second.value();
            auto v = boost::any_cast<std::string>( &value );

            if ( option.first == "search" ) {
                parametrs[1] = std::string( v->c_str() );
            }

            if ( option.first == "reaplace" ) {
                parametrs[2] = std::string( v->c_str() );
            }

            if ( option.first == "input-file" ) {
                parametrs[0] = std::string( v->c_str() );
            }
        }

        readAndReplaceFile( parametrs[0], parametrs[1], parametrs[2] );
        return 0;
    } else {
        std::cout << "Please, use --help option for information" << std::endl;
        return 1;
    }

    return 0;
}

bool cli::readAndReplaceFile( std::string nameFile, std::string stringToSearch, std::string stringToReplace )
{
    std::ifstream fileStreamRead( nameFile );
    std::string line;
    size_t index;
    char ch;
    auto FileSize = std::filesystem::file_size( nameFile );

    if ( fileStreamRead.is_open() ) {
        if ( FileSize > 1024 ) { //134217728
            while ( !fileStreamRead.eof() ) {
                for ( int i = 0; i < 1024; i++ ) {
                    fileStreamRead.get( ch );

                    if ( ch == '\n' ) {
                        break;
                    }

                    line += ch;
                }

                if ( line.find( stringToSearch ) < line.size() ) {
                    index = line.find( stringToSearch );
                    line.replace( index, stringToSearch.size(), stringToReplace );
                    std::cout << "The replacement, the result: " + line << std::endl;
                }

                line.clear();
            }
        } else {
            while ( getline( fileStreamRead, line ) ) {

                if ( line.find( stringToSearch ) ) {
                    index = line.find( stringToSearch );
                    line.replace( index, stringToSearch.size(), stringToReplace );
                    std::cout << "The replacement, the result: " + line << std::endl;
                    break;
                }
            }
        }
    } else {
        std::cout << "Error opening file" << std::endl;
    }

    fileStreamRead.close();
    return true;
}
