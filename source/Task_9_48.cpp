#include "tasks.h"

using namespace std;

void printRow( int* row, int iterations )
{
    for ( int i = 0; i < iterations; i++ ) {
        cout << row[i] << " ";
    }

    cout << endl;
}

void fill( int** matrix, int rows, int columns )
{
    for ( int row = 0; row < rows; row++ )
        for ( int i = 0; i < columns; i++ ) {
            matrix[row][i] = Random::get( 1, 10 );
        }
}

void print( int**  matrix, int row, int col )

{
    for ( int i = 0; i < row; i++ ) {
        for ( int j = 0; j < col; j++ ) {
            cout << matrix[i][j] << " " ;
        }

        cout << endl;
    }

}

int** allocate( int row, int cal )
{
    int** matrix = new int* [row];

    for ( int i = 0; i < row; ++i ) {
        matrix[i] = new int [cal];
    }

    return matrix;
}

int* Task_9_48_run( int* data[], int iterator )
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

    cout << "Line number with the maximum sum of elements: " << ++lineMax << endl;
    cout << "Line number with the minimun sum of elements: " << ++lineMin << endl;
    cout << "Product of rows: " << endl;
    lineMax--;
    lineMin--;
    int* result = new int[ iterator ];

    for ( int i = 0; i < iterator; i++ ) {
        result[i] = 0;

        for ( int j = 0; j < iterator; j++ ) {
            result[i] += data[lineMax][i] * data[lineMin][j];
        }

        cout << result[i] << " ";
    }

    cout << endl;
    return result;
}


