#include "tasks.h"

using namespace std;

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

    if ( Task_7_33_run_s( iterations, data ) ) {
        cout << "Coincidence" << endl;
    } else {
        cout << "Mismath" << endl;
    }
}
