// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "tasks.h"

#define iterators 10
#define testIterators 10

using namespace std;
/* Задача 9.48
  Дана квадратная матрица A(N×N). За один просмотр
  найти строку с минимальной суммой элементов и строку с максимальной суммой элементов
  и образовать произведение этих строк.
   */
int** initializingData( int a, int b )
{
    int** data;
    data = new int* [b];

    for ( int i = 0; i < a; i++ ) {
        data[i] = new int[b];
    }

    return data;
}

unsigned long long Task_9_48_run( int iterator )
{
    int sum, max, min, lineMax, lineMin;
    max = numeric_limits<int>::min();
    min = numeric_limits<int>::max();
    int data[iterators][iterators] = {{}};

    for ( int i = 0; i < iterators; i++ ) {
        for ( int j = 0; j < iterators; j++ ) {
            data[i][j] = Random::get( 1, 10 );
        }
    }

    auto start( chrono::high_resolution_clock::now() );

    for ( int i = 0; i < iterator; i++ ) {
        sum = 0;

        for ( int j = 0; j < iterator; j++ ) {
            sum += data[i][j];
        }

        if ( sum >= max ) {
            max = sum;
            lineMax = i;
        }

        if ( sum <= min ) {
            min = sum;
            lineMin = i;
        }
    }

    cout << "Line number with the maximum sum of elements: " << ++lineMax << endl;
    cout << "Line number with the minimun sum of elements: " << ++lineMin << endl;
    cout << "Composition: " << min* max << endl;
    auto end( chrono::high_resolution_clock::now() );
    auto duration( chrono::duration_cast<chrono::nanoseconds>( end - start ) );
    std::cout << "Duration: " << duration.count() << " ns" << endl;

    return ( min * max );
}

unsigned long long Task_9_48_run( int** data, int iterator )
{
    int sum, max, min, lineMax, lineMin;
    max = numeric_limits<int>::min();
    min = numeric_limits<int>::max();

    auto start( chrono::high_resolution_clock::now() );

    for ( int i = 0; i < iterator; i++ ) {
        sum = 0;

        for ( int j = 0; j < iterator; j++ ) {
            sum += data[i][j];
        }

        if ( sum >= max ) {
            max = sum;
            lineMax = i;
        }

        if ( sum < min ) {
            min = sum;
            lineMin = i;
        }
    }

    cout << "Line number with the maximum sum of elements: " << ++lineMax << endl;
    cout << "Line number with the minimun sum of elements: " << ++lineMin << endl;
    cout << "Composition: " << min* max << endl;
    auto end( chrono::high_resolution_clock::now() );
    auto duration( chrono::duration_cast<chrono::nanoseconds>( end - start ) );
    std::cout << "Duration: " << duration.count() << " ns" << endl;

    return ( min * max );
}
