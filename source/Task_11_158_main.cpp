#include "tasks.h"

using namespace std;

int main()
{
    /* Задача 11.158
    Удалить из массива все повторяющиеся элементы, оставив их первые вхождения,
    т.е. в массиве должны остаться только различные элементы.
    */
    const int iterations = 10;
    list<int> data, data2;
    myList l;

    for ( int i = 0; i < iterations; i++ ) {
        l.push_back( Random::get( 1, 10 ) );
    }


    cout << "Result: " << endl;
    l.unique_s();
    l.print();
    cout <<  endl;
    cout << "Finish" << endl;

    return 0;
}
