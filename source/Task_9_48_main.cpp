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

    int* matrix[iterations] = {{}};

    cout << "Data: " << endl;
    cout << endl;

    for ( int i = 0; i < iterations; i++ ) {
        matrix[i] = new int [iterations];

        for ( int j = 0; j < iterations; j++ ) {
            matrix[i][j] = Random::get( 1, 5 ) ;
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    Task_9_48_run( matrix, iterations );
    return 0;
}
