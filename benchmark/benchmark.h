#ifndef BENCHMARK_H
#define BENCHMARK_H
#include <benchmark/benchmark.h>
#include <iostream>
#include <list>
#include <chrono>
#include <ctime>
#include <string>
#include <ctime>
#include <list>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <filesystem>
#include "random.h"
#ifdef _WIN32
#pragma comment ( lib, "Shlwapi.lib" )
#ifdef _DEBUG
#pragma comment ( lib, "googlebenchmark-build/src/Debug/benchmark.lib" )
#pragma comment ( lib, "googlebenchmark-build/src/Debug/benchmark_main.lib" )
#else
#pragma comment ( lib, "benchmark.lib" )
#pragma comment ( lib, "benchmark_main.lib" )
#endif
#endif
#define RANGE 100

void merge( int merged[], int lenD, int L[], int lenL, int R[], int lenR );
void bubbleSort( int data[], int lenD );
void selectionSort( int data[], int lenD );
void mergeSort( int data[], int lenD );
void quickSort( int* data, int const len );
void insertionSort( int data[], int lenD );
void readDataFromFiles();
int* reverse( int in[], std::size_t len );
void createFiles();



#endif // BENCHMARK_H
