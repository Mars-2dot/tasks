#include "benchmark.h"

bool Task_7_33_run_new( int iteration, int data[] )
{
    bool result = false;
    int* first = &data[0];
    int* past = &data[0];
    int* next = &data[0];

    while ( ++first != &data[iteration - 1] ) {

        if ( *++past == *next++ ) {
            result = true;
            break;
        }
    }

    return result;
}

bool Task_7_33_run_squared( int iteration, int data[] )
{
    bool result = false;
    int* first = &data[0];
    int* firstNosted = &data[0];
    int* next = &data[0];
    int* past = &data[0];

//    for ( int i = 0 ; i < sizeof( data ) / sizeof( int ); i++ ) {
//        for ( int j = i + 1 ; j < sizeof( data ) / sizeof( int ); j++ ) {
//            if ( data[i] == data[j] ) {
//                return true;
//            }
//        }
//    }

    while ( ++first != &data[iteration - 1] ) {

        while ( ++firstNosted != &data[iteration - 1] ) {
            next++;

            if ( ( past != next ) && ( *past == *next )   ) {
                return true;
            }
        }

        ++past;
        firstNosted = &data[0];
    }

//    return false;
    return result;
}

void Task_7_33_Sort_run( int* data, int iteration )
{
    bool result;

    for ( int i = 0; i < iteration - 1; i++ ) {
        if ( data[i] == data[1 + i ] ) {
            result = true;
            break;
        }
    }
}

bool Task_7_33_run_squared_new( int data[] )
{
    for ( int i = 0 ; i < sizeof( data ) / sizeof( int ); i++ ) {
        for ( int j = i + 1 ; j < sizeof( data ) / sizeof( int ); j++ ) {
            if ( data[i] == data[j] ) {
                return true;
            }
        }
    }

    return false;
}

bool Task_7_33_run_squared_new_pointer( int data[] )
{
    for ( int* s = data, *t = data + sizeof( data ) / sizeof( int ); s < t; s++ ) {// На тесты
        for ( int* s1 = s + 1 ;  s1 < t; s1++ ) {
            if ( *s == *s1 ) {
                return false;
            }
        }
    }

    return false;
}

static void BM_Task_7_33_new_sort( benchmark::State& state )
{
    const int iterations = 5;
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_run_new( iterations,  data );
    }

    state.SetComplexityN( state.range( 0 ) );
}

static void BM_Task_7_33_squared( benchmark::State& state )
{
    const int iterations = 5;
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_run_squared( iterations,  data );
    }

    state.SetComplexityN( state.range( 0 ) );
}

static void BM_Task_7_33_Sort( benchmark::State& state )
{
    const int iterations = 5;
    int data[] = {1, 2, 3, 4, 4};
    quickSort( data, iterations );

    for ( auto _ : state ) {
        Task_7_33_Sort_run( data, iterations );
    }

    state.SetComplexityN( state.range( 0 ) );
}

static void BM_Task_7_33_SortInclude( benchmark::State& state )
{
    const int iterations = 5;
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_Sort_run( data, iterations );
        quickSort( data, iterations );
    }

    state.SetComplexityN( state.range( 0 ) );
}

static void BM_Task_7_33_squared_new( benchmark::State& state )
{
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_run_squared_new(   data );
    }

    state.SetComplexityN( state.range( 0 ) );
}

static void BM_Task_7_33_squared_new_pointer( benchmark::State& state )
{
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_run_squared_new_pointer( data );
    }

    state.SetComplexityN( state.range( 0 ) );
}

BENCHMARK( BM_Task_7_33_Sort )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_7_33_SortInclude )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_7_33_new_sort )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_7_33_squared )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_7_33_squared_new )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_7_33_squared_new_pointer )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
