#include <iostream>
#include <list>
#include "../random.h"

using namespace std;

list<int> unique_list( list<int> data )
{
    // Не работает, после первого вхождения вложенного цикла, i может указывать на не существующий элемент
//    for ( auto i = data.begin() ; i != data.end(); i++ ) {

//        for ( auto j = ++i; j != data.end(); j++ ) {

//            cout << *i << " " << *j << endl;

//            if ( *i == *j ) {
//                data.erase( j++ );
//            }
//        }

//        --i;
//    }



    return data;
}

list<int> unique_list_sort( list<int> data )
{
    data.sort();
    auto iter2 = data.begin();
    iter2++;

    for ( auto iter = data.begin(); iter != data.end(); ) {

        cout << *iter << " " << *iter2 << endl;

        if ( *iter == *iter2 ) {
            if ( iter2 == data.end() ) {
                break;
            }

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

    unique_list_sort( data );
    return 0;
}
