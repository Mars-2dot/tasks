#include "tasks.h"

using namespace std;

int main()
{
    /* Задача 11.158
    Удалить из массива все повторяющиеся элементы, оставив их первые вхождения,
    т.е. в массиве должны остаться только различные элементы.
    */
    const int iterations = 5;
    list<int> data, data2;

    for ( int i = 0; i < iterations; i++ ) {
        data.push_back( Random::get( 1, 5 ) );
    }

    data.sort();
    make_unique_new_s( data );

    for ( auto i = data.begin(); i != data.end(); i++ ) {
        cout << *i << endl;
    }

    return 0;
}
