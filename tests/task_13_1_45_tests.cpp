#include "tests.h"

using namespace std;

TEST( Task_13_1_45, fileTask )
{
    std::string result =  "String",
                test = "testString";
    std::string input = "/ftinput.txt",
                output = "/ftoutput.txt";
    wofstream fileWrite;
    wifstream fileRead;
    fileWrite.open( input );

    if ( fileWrite.is_open() ) {
        for ( int i = 0; i < 10; i++ ) {
//            fileWrite << test;
//            fileWrite << result ;
        }
    } else {
        EXPECT_TRUE( false );
    }

    fileWrite.close();
//    EXPECT_TRUE( reaplaceText( input, output, test, L"" ) );
}
