#include "benchmark.h"

static void BM_Task_11_158_sort( benchmark::State& state )
{
    std::list<int> data;
    data.push_back( 1 );
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 2 );
    data.push_back( 2 );

    for ( auto _ : state ) {
        make_unique_new_s( data );
    }
}

static void BM_Task_11_158_stdList( benchmark::State& state )
{
    std::list<int> data;
    data.push_back( 1 );
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 2 );
    data.push_back( 2 );

    for ( auto _ : state ) {
        data.unique();
    }
}

static void BM_Task_11_158_sort_stdList( benchmark::State& state )
{
    std::list<int> list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 1 );

    for ( auto _ : state ) {
        list.sort();
        list.unique();
    }
}

static void BM_Task_11_158_myList( benchmark::State& state )
{
    myList list;
    list.push_back( 1 );
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 2 );
    list.push_back( 2 );

    for ( auto _ : state ) {
        list.unique();
    }
}

static void BM_Task_11_158_sort_myList( benchmark::State& state )
{
    myList list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 1 );

    for ( auto _ : state ) {
        list.unique_s();
    }
}

static void BM_Task_11_158_sort_stdList_big_data( benchmark::State& state )
{
    std::list<int> list;

    for ( int i = 0; i < 1000; i++ ) {
        for ( int j = 0; j < 100; j++ ) {
            list.push_back( j );
        }
    }

    for ( auto _ : state ) {
        list.sort();
        list.unique();
    }
}

static void BM_Task_11_158_sort_myList_big_data( benchmark::State& state )
{
    myList list;

    for ( int i = 0; i < 1000; i++ ) {
        for ( int j = 0; j < 100; j++ ) {
            list.push_back( j );
        }
    }

    for ( auto _ : state ) {
        list.unique_s();
    }
}

static void BM_Task_11_158_myList_big_data( benchmark::State& state )
{
    myList list;

    for ( int i = 0; i < 100000; i++ ) {
        list.push_back( i );
    }

    for ( auto _ : state ) {
        list.unique();
    }
}

static void BM_Task_11_158_stdList_big_data( benchmark::State& state )
{
    std::list<int> data;

    for ( int i = 0; i < 100000; i++ ) {
        data.push_back( i );
    }

    for ( auto _ : state ) {
        data.unique();
    }
}


BENCHMARK( BM_Task_11_158_sort );
BENCHMARK( BM_Task_11_158_myList );
BENCHMARK( BM_Task_11_158_sort_myList );
BENCHMARK( BM_Task_11_158_stdList );
BENCHMARK( BM_Task_11_158_sort_stdList );
BENCHMARK( BM_Task_11_158_myList_big_data );
BENCHMARK( BM_Task_11_158_stdList_big_data );
BENCHMARK( BM_Task_11_158_sort_myList_big_data );
BENCHMARK( BM_Task_11_158_sort_stdList_big_data );
