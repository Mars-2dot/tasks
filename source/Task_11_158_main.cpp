#include "tasks.h"

using namespace std;

int main()
{
    /* Задача 11.158
    Удалить из массива все повторяющиеся элементы, оставив их первые вхождения,
    т.е. в массиве должны остаться только различные элементы.
    */
    const int size = 10;
    myList* list = new myList;

    Generate::list_recurent( list, size, 0, 5 );

    cout << "Source: ";
    list->print();

    cout << "Result: ";
    list->unique_s();
    list->print();
    cout << "Finish" << endl;

    return 0;
}
