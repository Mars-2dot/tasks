#include "benchmark.h"
#include "random.h"
using namespace std;


void fill( int** matrix, int rows, int columns )
{
    for ( int row = 0; row < rows; row++ )
        for ( int i = 0; i < columns; i++ ) {
            matrix[row][i] = Random::get( 1, 10 );
        }
}

void printRow( int* row, int iterations )
{
    for ( int i = 0; i < iterations; i++ ) {
        cout << row[i] << " ";
    }

    cout << endl;
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

int* Task_9_48_run( int** data, int iterator )
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

    int* result = new int[ iterator ];


    for ( int i = 0; i < iterator; i++ ) {
        result[i] += data[lineMax][i] * data[lineMin][i];
    }

    return result;
}

static void BM_Task_9_48( benchmark::State& state )
{
    const int iterations = 5;
    int** matrix = allocate( iterations, iterations );

    fill( matrix, iterations, iterations );

    for ( auto _ : state ) {
        Task_9_48_run( matrix, iterations );
    }

    state.SetComplexityN( state.range( 0 ) );
}


BENCHMARK( BM_Task_9_48 )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
