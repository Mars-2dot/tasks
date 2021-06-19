#include "tasks.h"

using namespace std;

int** allocate_old( int row, int cal )
{
    int** matrix = new int* [row];

    for ( int i = 0; i < row; ++i ) {
        matrix[i] = new int [cal];
    }

    return matrix;
}
int* allocate( int row, int cal )
{
    int* matrix = new int[row * cal];
    return matrix;
}

int Task_9_48_run( int* data, int iterator )
{
    int sum, max, min, lineMax = 0, lineMin = 0;
    max = numeric_limits<int>::min();
    min = numeric_limits<int>::max();

    for ( int i = 0; i < iterator; i++ ) {
        sum = 0;

        for ( int j = 0; j < iterator; j++ ) {
            sum += data[i * iterator + j];
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

    int result = 0;

    for ( int i = 0; i < iterator; i++ ) {
        result += data[lineMax * iterator + i] * data[lineMin * iterator + i];
    }

    return result;
}

int Task_9_48_run( int* data[], int iterator )
{

    int sum, max, min, lineMax = 0, lineMin = 0;
    max = numeric_limits<int>::min();
    min = numeric_limits<int>::max();

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

    int result = 0;

    for ( int i = 0; i < iterator; i++ ) {
        for ( int j = 0; j < iterator; j++ ) {
            result += data[lineMax][i] * data[lineMin][j];
        }
    }

    return result;
}


