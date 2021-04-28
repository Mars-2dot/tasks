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

    state.SetComplexityN( state.range( 0 ) );
}


BENCHMARK( BM_Task_9_48 )->RangeMultiplier( 2 )->Range( 1, 1 )->Complexity();
