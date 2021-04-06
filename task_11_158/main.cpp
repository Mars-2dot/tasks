#include <iostream>
#include <list>
#include "../random.h"

using namespace std;

list<int>& make_unique_s( list<int>& sorted )
{
    /*auto iter2 = sorted.begin();
    iter2++;*/

    for ( list<int>::iterator iter = sorted.begin(), iter2; iter != sorted.end(); ) {
        for ( iter2 = iter, iter2++; iter2 != sorted.end(); iter2++) {
            if ( *iter == *iter2 )
                sorted.erase( iter2 );
            else
                iter = iter2;
        }

        /*if ( iter2 == sorted.end() ) {
            break;
        }

        if ( *iter == *iter2 ) {
            sorted.erase( iter++ );
            iter2++;

        } else {
            iter2++;
            iter++;
        }*/
    }

    for ( auto i = sorted.begin(); i != sorted.end(); i++ ) {
        cout << *i << endl;
    }

    return sorted;
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

    data.sort();
    make_unique_s( data );
    return 0;
}
