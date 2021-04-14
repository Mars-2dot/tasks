#include "tasks.h"

using namespace std;

list<int>& make_unique_s( list<int>& sorted )
{
    for ( list<int>::iterator iter = sorted.begin(), iter2; iter != sorted.end(); ) {
        for ( iter2 = iter, iter2++; iter2 != sorted.end(); )
            if ( *iter == *iter2 ) {
                iter2 = sorted.erase( iter2 );
            } else {
                break;
            }

        iter = iter2;
    }

    return sorted;
}


