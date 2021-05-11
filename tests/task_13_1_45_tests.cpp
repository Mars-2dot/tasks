#include "tests.h"

using namespace std;

TEST( Task_13_1_45, fileTask )
{
    std::string result = "String", test = "testString";
    std::string fileName = std::filesystem::current_path().generic_string() + "/fileTest.txt";
    ofstream fileWrite;
    ifstream fileRead;
    fileWrite.open( fileName );

    if ( fileWrite.is_open() ) {
        for ( int i = 0; i < 10; i++ ) {
            fileWrite << test ;
            fileWrite << result ;
        }
    } else {
        EXPECT_TRUE( false );
    }

    fileWrite.close();
    EXPECT_TRUE( readAndReplaceFile( fileName, test, "" ) );
}
