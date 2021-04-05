#include "tests.h"

std::list<int> &make_unique( std::list<int> &data )
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
}

TEST( Task_11_158_Array, run )
{
    std::list<int> data;
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 3 );
    data.push_back( 4 );
    data.push_back( 5 );
    EXPECT_EQ( make_unique( data ), data );
    data.clear();
    data.push_back( 1 );
    data.push_back( 2 );
    data.push_back( 2 );
    data.push_back( 4 );
    data.push_back( 2 );
    std::list<int> result;
    result.push_back( 1 );
    result.push_back( 2 );
    result.push_back( 4 );
    EXPECT_EQ( make_unique( data ), result );
    data.clear();
    result.clear();
    data.push_back( 1 );
    data.push_back( 1 );
    data.push_back( 1 );
    data.push_back( 1 );
    data.push_back( 1 );
    result.push_back( 1 );
    EXPECT_EQ( make_unique( data ), result );
}
