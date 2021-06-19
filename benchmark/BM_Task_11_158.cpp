#include "benchmark.h"

int size = 1'000'000;
std::list<int>* data = Generate::list( size, 0, 5 );

static void Task_11_158( benchmark::State& state )
{
    for ( auto _ : state ) {
        data->sort();
        make_unique_s( *data );
    }
}

static void Task_11_158_std( benchmark::State& state )
{
    for ( auto _ : state ) {
        data->sort();
        data->unique();
    }
}

static void Task_11_158_myList( benchmark::State& state )
{
    myList list;
    list = data;

    for ( auto _ : state ) {
        list.unique_s();
    }
}

BENCHMARK( Task_11_158 );
BENCHMARK( Task_11_158_std );
BENCHMARK( Task_11_158_myList );
