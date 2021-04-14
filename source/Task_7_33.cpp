#include "tasks.h"

using namespace std;

void quickSort( int* data, int const len )
{
    int const lenD = len;
    int pivot = 0;
    int ind = lenD / 2;
    int i, j = 0, k = 0;

    if ( lenD > 1 ) {
        int* L = new int[lenD];
        int* R = new int[lenD];
        pivot = data[ind];

        for ( i = 0; i < lenD; i++ ) {
            if ( i != ind ) {
                if ( data[i] < pivot ) {
                    L[j] = data[i];
                    j++;
                } else {
                    R[k] = data[i];
                    k++;
                }
            }
        }

        quickSort( L, j );
        quickSort( R, k );

        for ( int cnt = 0; cnt < lenD; cnt++ ) {
            if ( cnt < j ) {
                data[cnt] = L[cnt];;
            } else if ( cnt == j ) {
                data[cnt] = pivot;
            } else {
                data[cnt] = R[cnt - ( j + 1 )];
            }
        }
    }
}

bool Task_7_33_run_s( int iterations, int data[] )
{
    for ( int i = 0 ; i < iterations; i++ ) {
        for ( int j = i + 1 ; j < iterations; j++ ) {
            if ( data[i] == data[j] ) {
                return true;
            }
        }
    }

    return false;
}

bool Task_7_33_run( int* data, int iteration )
{
    bool result;

    for ( int i = 0; i < iteration - 1; i++ ) {
        if ( data[i] == data[1 + i ] ) {
            result = true;
            break;
        }
    }

    return result;
}

bool Task_7_33_run_s_p( int data[] )
{
    for ( int* s = data, *t = data + sizeof( data ) / sizeof( int ); s < t; s++ ) {
        for ( int* s1 = s + 1 ;  s1 < t; s1++ ) {
            if ( *s == *s1 ) {
                return false;
            }
        }
    }

    return false;
}
