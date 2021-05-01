#include "benchmark.h"
#include "random.h"
using namespace std;

static void BM_Task_9_48( benchmark::State& state )
{
    const int iterations = 5;
    int** matrix = allocate( iterations, iterations );

    fill( matrix, iterations, iterations );

    for ( auto _ : state ) {
        Task_9_48_run( matrix, iterations );
    }
}


BENCHMARK( BM_Task_9_48 );
