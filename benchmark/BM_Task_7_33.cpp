#include "benchmark.h"

static void BM_Task_7_33( benchmark::State& state )
{
    const int iterations = 5;
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_run( data, iterations );
    }
}

static void BM_Task_7_33_s_p( benchmark::State& state )
{
    int data[] = {1, 2, 3, 4, 4};

    for ( auto _ : state ) {
        Task_7_33_run_s_p( data );
    }
}

BENCHMARK( BM_Task_7_33 );
BENCHMARK( BM_Task_7_33_s_p );
