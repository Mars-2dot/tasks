#include "benchmark.h"

static void BM_Task_7_33_run( benchmark::State& state )
{
    const int iterations = 5;
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_run( data, iterations );
    }

    state.SetComplexityN( state.range( 0 ) );
}

static void BM_Task_7_33_s( benchmark::State& state )
{
    const int iterations = 5;
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_run_s( iterations,  data );
    }

    state.SetComplexityN( state.range( 0 ) );
}

static void BM_Task_7_33_s_p( benchmark::State& state )
{
    const int iterations = 5;
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_run_s_p( data );
    }

    state.SetComplexityN( state.range( 0 ) );
}

BENCHMARK( BM_Task_7_33_run )->RangeMultiplier( 2 )->Range( 1, 1 )->Complexity();
BENCHMARK( BM_Task_7_33_s )->RangeMultiplier( 2 )->Range( 1, 1 )->Complexity();
BENCHMARK( BM_Task_7_33_s_p )->RangeMultiplier( 2 )->Range( 1, 1  )->Complexity();
