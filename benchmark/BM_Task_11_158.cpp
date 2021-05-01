#include "benchmark.h"

static void BM_Task_11_158_old_sort( benchmark::State& state )
{
    std::list<int> data;
    data.push_back( 1 );
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 2 );
    data.push_back( 2 );

    for ( auto _ : state ) {
        make_unique_s( data );
    }
}

static void BM_Task_11_158_new_sort( benchmark::State& state )
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

static void BM_Task_11_158_sort_std( benchmark::State& state )
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

static void BM_Task_11_158_new_sort_second_variant( benchmark::State& state )
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

BENCHMARK( BM_Task_11_158_old_sort );
BENCHMARK( BM_Task_11_158_new_sort );
BENCHMARK( BM_Task_11_158_new_sort_second_variant );
BENCHMARK( BM_Task_11_158_sort_std );
