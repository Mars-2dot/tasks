#pragma once
#include <iostream>

using namespace std;
void Task_7_33_run( int* data, int iteration )
{
//    Проверить, все ли элементы массива различны.
    int* current, *end = data + iteration - 1;

    for ( current = data + 1; data < end; data++, current = data + 1 ) {
        while ( current <= end ) {
            if ( *current == *data ) {
                *current = *end--;
            } else {
                current++;
            }
        }
    }

    for ( int i = 0; i < iteration; i++ ) {
        std::cout << data[i] << std::endl;
    }
}
int main()
{
    const int iterations = 5;
    int data[iterations];

    for ( int i = 0; i < iterations; i++ ) {
        data[i] = Random::get( 1, 5 );
    }

    Task_7_33_run(  data, iterations );

}
