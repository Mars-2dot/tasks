#include "tasks.h"
#include <fcntl.h>
#include <io.h>
#include <locale>
#ifdef _WIN32
    #include <windows.h>
#endif

bool readAndReplaceFile( std::string nameFile, std::string search, std::string replace )
{
//    _setmode( _fileno( stdout ), _O_U16TEXT );
#ifdef _WIN32
    SetConsoleCP( 1251 );
    SetConsoleOutputCP( 1251 );
#endif
//    SetConsoleCP( 65001 );
//    SetConsoleOutputCP( 65001 );
//    setlocale( LC_CTYPE, "Russia" );
//    system( "chcp 65001" );


    std::ifstream fileStreamRead( nameFile );
    std::string line;
    size_t index;
    char ch;
    auto FileSize = std::filesystem::file_size( nameFile );

    if ( fileStreamRead.is_open() ) {
        if ( FileSize > 1024 ) { //134217728 // checking the file size, if larger, then reading by blocks until the file ends
            while ( !fileStreamRead.eof() ) {
                for ( int i = 0; i < 1024; i++ ) {
                    fileStreamRead.get( ch );

                    if ( ch == '\n' ) {
                        break;
                    }

                    line += ch;
                }

                if ( line.find( search ) < line.size() ) {
                    index = line.find( search );
                    line.replace( index, search.size(), replace );
                    std::cout << "LThe replacement, the result: ";
                    std::cout << line << std::endl;
                }

                line.clear();
            }
        } else {
            while ( getline( fileStreamRead, line ) ) {

                if ( line.find( search ) ) {
                    index = line.find( search );
                    line.replace( index, search.size(), replace );
                    std::cout << "The replacement, the result: " << std::endl;
                    std::cout << line << std::endl;
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
