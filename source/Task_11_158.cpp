#include "tasks.h"

using namespace std;

list<int>& make_unique_s( list<int>& sorted )
{
    for ( list<int>::iterator iter = sorted.begin(), iter2 = iter++; iter != sorted.end(); iter++ ) {
        if ( *iter == *iter2 ) {
            iter2 = sorted.erase( iter2 );
        } else {
            iter2++;
        }
    }

    return sorted;
}
