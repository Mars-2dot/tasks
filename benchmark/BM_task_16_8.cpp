#pragma once
#include "benchmark.h"

std::string path = std::filesystem::current_path().generic_string() + "/Task16_8.txt";
std::string pathSort = std::filesystem::current_path().generic_string() + "/Task16_8Sort.txt";
int dataSort[RANGE] = {};
int dataTestSort[RANGE] = {};

static void BM_Task_16_8_quick( benchmark::State& state )
{

    createFiles();
    readDataFromFiles();

    int dataMixed[RANGE] = {};

    for ( int i = 0; i < RANGE; i++ ) {
        dataMixed[i] = dataSort[i];
    }

    for ( auto _ : state ) {
        quickSort( dataMixed, RANGE );
    }

    state.SetComplexityN( state.range( 0 ) );
}

static void BM_Task_16_8_merge( benchmark::State& state )
{
    createFiles();
    readDataFromFiles();
    int dataMixed[RANGE] = {};

    for ( int i = 0; i < RANGE; i++ ) {
        dataMixed[i] = dataSort[i];
    }

    for ( auto _ : state ) {
        mergeSort( dataMixed, RANGE );
    }

    state.SetComplexityN( state.range( 0 ) );

}
static void BM_Task_16_8_selection( benchmark::State& state )
{
    createFiles();
    readDataFromFiles();
    int dataMixed[RANGE] = {};

    for ( int i = 0; i < RANGE; i++ ) {
        dataMixed[i] = dataSort[i];
    }

    for ( auto _ : state ) {
        selectionSort( dataMixed, RANGE );
    }

    state.SetComplexityN( state.range( 0 ) );

}

static void BM_Task_16_8_insertion( benchmark::State& state )
{
    createFiles();
    readDataFromFiles();
    int dataMixed[RANGE] = {};

    for ( int i = 0; i < RANGE; i++ ) {
        dataMixed[i] = dataSort[i];
    }

    for ( auto _ : state ) {
        insertionSort( dataMixed, RANGE );
    }

    state.SetComplexityN( state.range( 0 ) );

}

static void BM_Task_16_8_bubble( benchmark::State& state )
{
    createFiles();
    readDataFromFiles();
    int dataMixed[RANGE] = {};

    for ( int i = 0; i < RANGE; i++ ) {
        dataMixed[i] = dataSort[i];
    }

    for ( auto _ : state ) {
        bubbleSort( dataMixed, RANGE );
    }

    state.SetComplexityN( state.range( 0 ) );
}

void createFiles()
{
    std::ofstream outFile;


    outFile.open( path );

    if ( outFile.is_open() ) {
        for ( int i = 0; i < RANGE; i++ ) {
            dataSort[i] = Random::get( 1, RANGE * 10 );
            outFile << std::to_string( dataSort[i] ).c_str() << std::endl;
        }
    }

    outFile.close();
    quickSort( dataSort, RANGE );
    std::ofstream out2;
    out2.open( pathSort );

    if ( out2.is_open() ) {
        for ( int i = 0; i < RANGE; i++ ) {
            out2 << dataSort[i] << std::endl;
        }
    }

    out2.close();
}

void readDataFromFiles()
{
    std::ifstream fileStreamRead( path );
    std::string line;
    int count = 0;

    while ( getline( fileStreamRead, line ) ) {
        dataSort[count] = stoi( line );
        count++;
    }

    std::ifstream fileStreamReadSort( pathSort );
    count = 0;

    while ( getline( fileStreamRead, line ) ) {
        dataTestSort[count] = stoi( line );
        count++;
    }
}

BENCHMARK( BM_Task_16_8_quick )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_16_8_merge )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_16_8_insertion )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_16_8_selection )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
BENCHMARK( BM_Task_16_8_bubble )->RangeMultiplier( 2 )->Range( 1 << 10, 1 << 18 )->Complexity();
