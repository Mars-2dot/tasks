#include "tests.h"

using namespace std;

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
