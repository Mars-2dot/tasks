#include "tasks.h"

using namespace std;

int main()
{
    /* Задача 11.158
    Удалить из массива все повторяющиеся элементы, оставив их первые вхождения,
    т.е. в массиве должны остаться только различные элементы.
    */
    const int iterations = 10;
    myList* l = new myList;
    Random::list_recurent( l, iterations, 0, 5 );

    cout << "Source: ";
    l->print();

    cout << "Result: ";
    l->unique_s();
    l->print();
    cout << "Finish" << endl;

    return 0;
}
