#include "tasks.h"

using namespace std;

int main()
{
    /* Задача 11.158
    Удалить из массива все повторяющиеся элементы, оставив их первые вхождения,
    т.е. в массиве должны остаться только различные элементы.
    */
    const int iterations = 80000;
    list<int> data, data2;
    myList l;

    for ( int i = 0; i < iterations; i++ ) {
<<<<<<< HEAD
        l.push_back( Random::get( 1, 1000 ) );
//        l.print();
    }

//    for ( int i = 0; i < 10; i++ ) {
//        for ( int j = 0; j < 10; j++ ) {
//        l.push_back( i );
//        }
//    }


    cout << "Result: " << endl;
=======
        l.push_back( Random::get( 1, 5 ) );
        l.print();
    }

    cout << "Result: ";
>>>>>>> b8a2a7ff79b426244500947065b4e146bdc4a416
    l.unique_s();
    l.print();
    cout <<  endl;
    cout << "Finish";

    return 0;
}
