#include "benchmark.h"

static void BM_Task_11_158_sort( benchmark::State& state )
{
    std::list<int> data;
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 2 );
    data.push_back( 1 );
    data.push_back( 2 );
    data.sort();

    for ( auto _ : state ) {
        make_unique_s( data );
    }
}

static void BM_Task_11_158_new_sort( benchmark::State& state )
{
    std::list<int> data;
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 2 );
    data.push_back( 1 );
    data.push_back( 2 );
    data.sort();

    for ( auto _ : state ) {
        make_unique_new_s( data );
    }
}

static void BM_Task_11_158_sort_std( benchmark::State& state )
{
    std::list<int> data;
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 2 );
    data.push_back( 1 );
    data.push_back( 2 );

    for ( auto _ : state ) {
        data.sort();
        data.unique();
    }
}

BENCHMARK( BM_Task_11_158_sort );
BENCHMARK( BM_Task_11_158_new_sort );
BENCHMARK( BM_Task_11_158_sort_std );
