#include <iostream>
#include "../random.h"

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

bool Task_7_33_run_squared_new( int iterations, int data[] )
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

int main()
{
//    Проверить, все ли элементы массива различны.
    const int iterations = 5;
    int data[iterations];

//    data[0] = 1;
//    data[1] = 2;
//    data[2] = 3;
//    data[3] = 4;
//    data[4] = 5;

    for ( int i = 0; i < iterations; i++ ) {
        data[i] = Random::get( 1, 5 );
        cout << data[i] << endl;
    }

    if ( Task_7_33_run_squared_new( iterations, data ) ) {
        cout << "Coincidence" << endl;
    } else {
        cout << "Mismath" << endl;
    }
}
