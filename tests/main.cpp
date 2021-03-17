<<<<<<< HEAD
#include "tests.h"
=======
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <iostream>
#include "gtest/gtest.h"
#include "../tasks.h"

namespace
{
TEST( Task_2_40, Run )
{
    ASSERT_EQ( Task_2_40_run( 180 ), "60" );
    ASSERT_EQ( Task_2_40_run( 60 ), "20" );
    ASSERT_EQ( Task_2_40_run( 120 ), "40" );
}
TEST( Task7_33, run )
{
    int dataFalse[5] = {1, 2, 3, 4, 5};
//    ASSERT_FALSE( Task_7_33_run( 5, dataFalse ) );
    int dataTrue[5] = {2, 2, 3, 4, 5};
//    ASSERT_TRUE( Task_7_33_run( 5, dataTrue ) );
}

TEST( Task7_67, run )
{
    int dataEQ[5] = {0, 2, 2, 2, 0};
    ASSERT_EQ( Task_7_67_run( dataEQ, 5 ), 3 );

    int dataNotEQ[5] = {0, 7, 2, 2, 7};
    ASSERT_EQ( Task_7_67_run( dataNotEQ, 5 ), 2 );
}
TEST( Task9_48, run )
{
    int** data;
    int testIterators = 10;
    data = new int* [testIterators];

    for ( int i = 0; i < testIterators; i++ ) {
        data[i] = new int[testIterators];
    }

    for ( int i = 0; i < testIterators; i++ ) {
        for ( int j = 0; j < testIterators; j++ ) {
            data[i][j] = 1;
        }
    }

    for ( int i = 0; i < testIterators; i++ ) {
        data[0][i] = 2;
    }

    ASSERT_EQ( Task_9_48_run( data, testIterators ), testIterators * ( testIterators * 2 ) );
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
>>>>>>> 4a157a7 (test commit 3)

//int main( int argc, char** argv )
//{
//    ::testing::InitGoogleTest( &argc, argv );
//    return RUN_ALL_TESTS();
//}
