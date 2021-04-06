#include <list>
using namespace std;

#include "tests.h"

list<int>& make_unique_s( list<int>& sorted )
{
    for ( list<int>::iterator iter = sorted.begin(), iter2; iter != sorted.end(); ) {
        for ( iter2 = iter, iter2++; iter2 != sorted.end(); )
            if ( *iter == *iter2 )
                iter2 = sorted.erase( iter2 );
            else
                break;
        iter = iter2;
    }

    return sorted;
}
/*std::list<int> &make_unique( std::list<int> &data )
{
    data.sort();
    auto iter2 = data.begin();
    iter2++;

    for ( auto iter = data.begin(); iter != data.end(); ) {

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

    return data;
}*/

TEST( Task_11_158_Array, run )
{
    std::list<int> data;
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 3 );
    data.push_back( 4 );
    data.push_back( 5 );
    data.sort();
    EXPECT_EQ( make_unique_s( data ), data );
    data.clear();
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 2 );
    data.push_back( 4 );
    data.push_back( 2 );
    data.sort();
    std::list<int> result;
    result.push_back( 1 );
    result.push_back( 2 );
    result.push_back( 4 );
    data.sort();
    EXPECT_EQ( make_unique_s( data ), result );
    data.clear();
    result.clear();
    data.push_back( 1 );
    data.push_back( 1 );
    data.push_back( 1 );
    data.push_back( 1 );
    data.push_back( 1 );
    result.push_back( 1 );
    data.sort();
    EXPECT_EQ( make_unique_s( data ), result );
}
