#include "tests.h"

TEST( Task9_48, run )
{
    int** data;
    int testIterators = 3;
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

    int* result = Task_9_48_run( data, testIterators );
    int productRow = 0;

    for ( int i = 0; i < testIterators; i++ ) {
        productRow += result[i];
    }

    ASSERT_EQ( productRow, 3 );
}
