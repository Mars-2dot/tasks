#include "tests.h"

int* Task_9_48_run( int** data, int iterator )
{
    int sum, max, min, lineMax = 0, lineMin = 0;
    max = std::numeric_limits<int>::min();
    min = std::numeric_limits<int>::max();

    for ( int i = 0; i < iterator; i++ ) {
        sum = 0;

        for ( int j = 0; j < iterator; j++ ) {
            sum += data[i][j];
        }

        if ( sum >= max ) {
            max = sum;
            lineMax = i;
        }

        if ( sum < min ) {
            min = sum;
            lineMin = i;
        }
    }

    int* result = new int[ iterator ];

    for ( int i = 0; i < iterator; i++ ) {
        result[i] = 0;
        result[i] += data[lineMax][i] * data[lineMin][i];
    }

    std::cout << "Line number with the maximum sum of elements: " << ++lineMax << std::endl;
    std::cout << "Line number with the minimun sum of elements: " << ++lineMin << std::endl;
    std::cout << "Product of rows: " << std::endl;

    return result;
}

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

    ASSERT_EQ( productRow, 6 );
}
