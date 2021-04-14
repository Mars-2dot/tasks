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

    int** matrix = allocate( iterations, iterations );
    fill( matrix, iterations, iterations );
    cout << "Data: " << endl;
    print( matrix, iterations, iterations );
    cout << endl;
    int* result = new int[iterations];
    result = Task_9_48_run( matrix, iterations );
    printRow( result, iterations );
    return 0;
}
