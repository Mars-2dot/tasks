#include <iostream>
#include <list>
#include "../random.h"

using namespace std;

list<int>& make_unique( list<int>& data )
{
    data.sort();
    auto iter2 = data.begin();
    iter2++;

    for ( auto iter = data.begin(); iter != data.end(); ) {

        if ( iter2 == data.end() ) {
            break;
        }

        if ( *iter == *iter2 ) {
            data.erase( iter++ );
            iter2++;

        } else {
            iter2++;
            iter++;
        }
    }

    for ( auto i = data.begin(); i != data.end(); i++ ) {
        cout << *i << endl;
    }

    return data;
}

int main()
{
    /* Задача 11.158
    Удалить из массива все повторяющиеся элементы, оставив их первые вхождения,
    т.е. в массиве должны остаться только различные элементы.
    */
    const int iterations = 5;
    list<int> data;

    for ( int i = 0; i < iterations; i++ ) {
        data.push_back( Random::get( 1, 5 ) );
    }

    make_unique( data );
    return 0;
}
