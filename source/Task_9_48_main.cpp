#include "tasks.h"

const int iterations = 3;

using namespace std;

int main()
{
    /* Задача 9.48
     Дана квадратная матрица A(N×N). За один просмотр
     найти строку с минимальной суммой элементов и строку с максимальной суммой элементов
     и образовать произведение этих строк.
      */

    int* matrix = allocate( iterations, iterations );

    cout << "Data: " << endl;
    cout << endl;

    for ( int i = 0; i < iterations; i++ ) {
        for ( int j = 0; j < iterations; j++ ) {
            matrix[i * iterations + j ] = Random::get( 1, 5 ) ;
            cout << matrix[i * iterations + j] << " ";
        }

        cout << endl;
    }

    int result = Task_9_48_run( matrix, iterations );
    cout << "Produce of rows: " << result << endl;
    return 0;
}
