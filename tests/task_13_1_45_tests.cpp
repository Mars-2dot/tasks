#include "tests.h"

using namespace std;

bool readAndReplaceFile( std::string nameFile, std::string stringToSearch, std::string stringToReplace )
{
    ifstream fileStreamRead( nameFile );
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

TEST( Task_13_1_45, fileTask )
{
    std::string stringCorrect = "", filePath = std::filesystem::current_path().generic_string() + "/";
    std::string stringForTest = " ";
//    readAndReplaceFile( "testFile.txt", "test", "Needs" );
    std::ifstream out( filePath + "testFileAfter.txt" );

    if ( out.is_open() ) {
        std::string str;

        while ( getline( out, str ) ) {
            stringCorrect = str;
        }

        out.close();
        EXPECT_FALSE( stringCorrect == stringForTest );

        readAndReplaceFile( "testFile.txt", "test", "needs" );

        EXPECT_TRUE( stringCorrect == stringForTest );
    }
}
