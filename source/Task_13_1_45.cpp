#include "tasks.h"
#include <fcntl.h>
#include <io.h>
#include <locale>
#include <codecvt>
#include <windows.h>

bool reaplaceText( std::string input, std::string output, std::string search, std::string replace )
{
    system( "chcp 1251" );
//    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//    std::wstring wInput = converter.from_bytes( input ), wOutput = converter.from_bytes( output ),
//                 wSearch = converter.from_bytes( search ), wReplace = converter.from_bytes( replace );
    std::ifstream fileStreamRead( input  );
    std::ofstream fileStreamWrite( output );
    std::string::size_type blockSize = 1024, fileCount = 0;
    std::string line;
    size_t index;
    char ch;

    if ( fileStreamRead.is_open() ) {
        while ( !fileStreamRead.eof() ) {
            for ( std::string::size_type i = 0; i < blockSize + search.size(); i++ ) {
                fileStreamRead.get( ch );

                if ( ch == '\n' ) {
                    break;
                }

                line += ch;
                fileCount++;
            }

            if ( line.find( search ) < line.size() ) {
                index = line.find( search );
                line.replace( index, search.size(), replace );
                fileCount = fileCount + replace.size();
                fileStreamRead.seekg( fileCount );
                std::cout << "The replacement, the result: ";
                std::cout << line << std::endl;
            }

            if ( fileStreamWrite.is_open() ) {
                fileStreamWrite << line;

                if ( line[line.size()] == '\n' ) {
                    fileStreamWrite << std::endl;
                }
            }

            line.clear();
        }
    } else {
        std::cout << "Error opening file" << std::endl;
    }

    fileStreamRead.close();
    return true;
}
//    _setmode( _fileno( stdout ), _O_U16TEXT );
//fix code page to utf-8
//cute ones variant of work witch file
//    SetConsoleCP( 65001 );
//    SetConsoleOutputCP( 65001 );
//    setlocale( LC_CTYPE, "Russia" );
//    system( "chcp 65001" );

