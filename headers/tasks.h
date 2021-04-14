#ifndef TASKS_H
#define TASKS_H
#include <chrono>
#include <ctime>
#include <string>
#include <ctime>
#include <list>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include "random.h"

void quickSort( int* data, int const len );
void printRow( int* row, int iterations );
void fill( int** matrix, int rows, int columns );
void print( int**  matrix, int row, int col );
int** allocate( int row, int cal );
int* Task_9_48_run( int** data, int iterator );
std::list<int>& make_unique_s( std::list<int>& sorted );
bool Task_7_33_run( int* data, int iteration );
bool Task_7_33_run_s( int iterations, int data[] );
bool Task_7_33_run_s_p( int data[] );
bool readAndReplaceFile( std::string nameFile, std::string stringToSearch, std::string stringToReplace );

#endif // TASKS_H