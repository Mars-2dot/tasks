#include "tests.h"

bool Task_7_33_run_squared_new( int iterations, int data[] )
{
    for ( int i = 0 ; i < iterations; i++ ) {
        for ( int j = i + 1 ; j < iterations; j++ ) {
            if ( data[i] == data[j] ) {
                return true;
            }
        }
    }

    return false;
}

namespace
{

TEST( Task7_33, run )
{
    int dataFalse[5] = {1, 2, 3, 4, 5};
    ASSERT_FALSE( Task_7_33_run_squared_new( 5, dataFalse ) );
    int dataTrue[5] = {2, 2, 3, 4, 5};
    ASSERT_TRUE( Task_7_33_run_squared_new( 5, dataTrue ) );
    int dataTrueNotSort[5] = {2, 1, 3, 2, 5};
    ASSERT_TRUE( Task_7_33_run_squared_new( 5, dataTrueNotSort ) );
    dataFalse[0] = 5;
    dataFalse[1] = 4;
    dataFalse[2] = 3;
    dataFalse[3] = 2;
    dataFalse[4] = 1;
    ASSERT_FALSE( Task_7_33_run_squared_new( 5, dataFalse ) );
}
/*
TEST( Task7_67, run )
{
    int dataEQ[5] = {0, 2, 2, 2, 0};
    ASSERT_EQ( Task_7_67_run( dataEQ, 5 ), 3 );

    int dataNotEQ[5] = {0, 7, 2, 2, 7};
    ASSERT_EQ( Task_7_67_run( dataNotEQ, 5 ), 2 );
}

TEST( Task9_187, run )
{
    ASSERT_EQ( Task_9_187_run( 42 ), " сорок два" );
    ASSERT_EQ( Task_9_187_run( 102 ), "сто два" );
    ASSERT_EQ( Task_9_187_run( 451 ), "четыреста пятьдесят один" );
    ASSERT_EQ( Task_9_187_run( 974 ), "девятьсот семьдесят четыре" );
}
TEST( Task_11_158_Array, run )
{
    int data[5] = {4, 4, 2, 1, 4};
    int dataFinal[3] = {4, 2, 1};
    int newSize = 0;
    int* newData = uniq( data, sizeof( data ) / sizeof( int ), newSize );
    EXPECT_TRUE( 0 == memcmp( newData, dataFinal, sizeof( dataFinal ) ) );
}


TEST( Task13_2_8, run )
{
    int minimum = 2, maximum = 2 ;
    std::string path =  "testFile.txt";
    std::ofstream file( path );

    if ( file.is_open() ) {
        file << 3.14 << std::endl << 4.22 << std::endl << 34.22 << std::endl << 2.55 << std::endl << 5.44;
    } else {
        std::cout << "File not open" << std::endl;
    }

    file.close();
    ASSERT_EQ(  ( minimum + maximum ) * 2, Task_13_2_8_run( 5, path ) );
    remove( "testFile.txt" );
}

TEST( Task16_8, quickSort )
{
    int dataTemp[5];
    std::string pathForTest = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8.txt";
    std::string pathForTestSort = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8Sort.txt";
    int dataMixedGTest[5] = {2, 5, 3, 4, 1};
    int dataSortGTest[5] = {1, 2, 3, 4, 5};

    for ( int i = 0; i < 5; i++ ) {
        dataTemp[i] = dataMixedGTest[i];
    }

    quickSort( dataTemp, 5 );
    EXPECT_TRUE( 0 == memcmp( dataTemp, dataSortGTest, sizeof( dataMixedGTest ) ) );
}

TEST( Task16_8, mergeSort )
{
    int dataTemp[5];
    std::string pathForTest = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8.txt";
    std::string pathForTestSort = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8Sort.txt";
    int dataMixedGTest[5] = {2, 5, 3, 4, 1};
    int dataSortGTest[5] = {1, 2, 3, 4, 5};

    for ( int i = 0; i < 5; i++ ) {
        dataTemp[i] = dataMixedGTest[i];
    }

    mergeSort( dataTemp, 5 );
    EXPECT_TRUE( 0 == memcmp( dataTemp, dataSortGTest, sizeof( dataMixedGTest ) ) );
}

TEST( Task16_8, insertionSort )
{
    int dataTemp[5];
    std::string pathForTest = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8.txt";
    std::string pathForTestSort = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8Sort.txt";
    int dataMixedGTest[5] = {2, 5, 3, 4, 1};
    int dataSortGTest[5] = {1, 2, 3, 4, 5};

    for ( int i = 0; i < 5; i++ ) {
        dataTemp[i] = dataMixedGTest[i];
    }

    insertionSort( dataTemp, 5 );
    EXPECT_TRUE( 0 == memcmp( dataTemp, dataSortGTest, sizeof( dataMixedGTest ) ) );
}

TEST( Task16_8, selectionSort )
{
    int dataTemp[5];
    std::string pathForTest = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8.txt";
    std::string pathForTestSort = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8Sort.txt";
    int dataMixedGTest[5] = {2, 5, 3, 4, 1};
    int dataSortGTest[5] = {1, 2, 3, 4, 5};

    for ( int i = 0; i < 5; i++ ) {
        dataTemp[i] = dataMixedGTest[i];
    }

    selectionSort( dataTemp, 5 );
    EXPECT_TRUE( 0 == memcmp( dataTemp, dataSortGTest, sizeof( dataMixedGTest ) ) );
}

TEST( Task16_8, bubbleSort )
{
    int dataTemp[5];
    std::string pathForTest = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8.txt";
    std::string pathForTestSort = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8Sort.txt";
    int dataMixedGTest[5] = {2, 5, 3, 4, 1};
    int dataSortGTest[5] = {1, 2, 3, 4, 5};

    for ( int i = 0; i < 5; i++ ) {
        dataTemp[i] = dataMixedGTest[i];
    }

    bubbleSort( dataTemp, 5 );
    EXPECT_TRUE( 0 == memcmp( dataTemp, dataSortGTest, sizeof( dataMixedGTest ) ) );
}


} //namespace

*/


}//namespace
