#include "tests.h"

TEST( Task9_48, run )
{
    int* data;
    int iterations = 3;
    data = allocate( iterations, iterations );

    for ( int i = 0; i < iterations; i++ ) {
        for ( int j = 0; j < iterations; j++ ) {
            data[i * iterations + j] = 1;
        }
    }

    for ( int i = 0; i < iterations; i++ ) {
        data[i * 1 + iterations] = 2;
    }

    int result = Task_9_48_run( data, iterations );

    ASSERT_EQ( result, 6 );
}
