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

    state.SetComplexityN( state.range( 0 ) );
}

static void BM_Task_11_158_sort_std( benchmark::State& state )
{
    std::list<int> data;
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 2 );
    data.push_back( 1 );
    data.push_back( 2 );

    data.sort();

    for ( auto _ : state ) {
        data.unique();
    }

    state.SetComplexityN( state.range( 0 ) );
}

BENCHMARK( BM_Task_11_158_sort )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_11_158_sort_std )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
