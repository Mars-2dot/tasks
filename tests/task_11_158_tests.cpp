#include "tests.h"
using namespace std;

TEST( Task_11_158_s, run )
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
