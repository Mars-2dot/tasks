#include "benchmark.h"
#include <list>

std::list<int> unique_list_sort( std::list<int> data )
{
    auto iter2 = data.begin();
    iter2++;

    for ( auto iter = data.begin(); iter != data.end(); ) {

        if ( *iter == *iter2 ) {
            data.erase( iter++ );
            iter2++;

            if ( iter2 == data.end() ) {
                break;
            }
        } else {
            iter2++;
            iter++;
        }
    }

    return data;
}

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
        unique_list_sort( data );
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
