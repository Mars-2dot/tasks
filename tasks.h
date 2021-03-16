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

void createFile( std::string path, int range );
void Task_7_33_run( int* data, int iteration );
void Task_2_40_run();
std::string Task_2_40_run( int y );
int Task_7_67_run( int data[], int length );
int** initializingData( int a, int b );
unsigned long long Task_9_48_run( int iterator );
unsigned long long Task_9_48_run( int** data, int iterator );
std::string Task_9_187_run( int number );
bool inData( int* data, int need, int count );
int* uniq( int* data, int size, int& newSize );
std::list<int> myUnique( std::list<int> data );
bool readAndReplaceFile( std::string nameFile, std::string stringToSearch, std::string stringToReplace );
int Task_13_2_8_run( int range, std::string path );
void selectionSort( int data[], int lenD );
void bubbleSort( int data[], int lenD );
void merge( int merged[], int lenD, int L[], int lenL, int R[], int lenR );
void mergeSort( int data[], int lenD );
void insertionSort( int data[], int lenD );
void quickSort( int* data, int const len );
void createFiles();
void readDataFromFiles();
int* reverse( int in[], std::size_t len );

//std::string pathForTest = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8.txt";
//std::string pathForTestSort = std::filesystem::current_path().generic_string() + "/GoogleTest_Task16_8Sort.txt";
//const int RANGE = 10000;
//int dataForSort[RANGE] = {};
//int dataForGTestSort[RANGE] = {};
//int dataMixedGTest[5] = {2, 5, 3, 4, 1};
//int dataSortGTest[5] = {1, 2, 3, 4, 5};


#endif // TASKS_H
