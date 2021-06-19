#include "tasks.h"

using namespace std;

bool Task_7_33_run( int* data, int iteration )
{
    for ( int i = 0; i < iteration - 1; i++ ) {
        if ( data[i] == data[1 + i ] ) {
            return true;
            break;
        }
    }

    return false;
}

bool Task_7_33_run_s_p( int* data )
{
    for ( int* s = data, *t = data + sizeof( data ) / sizeof( int ); s < t; s++ ) {
        for ( int* s1 = s + 1 ;  s1 < t; s1++ ) {
            if ( *s == *s1 ) {
                return true;
            }
        }
    }

    return false;
}
