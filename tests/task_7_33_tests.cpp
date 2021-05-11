#include "tests.h"

TEST( Task7_33, run )
{
    int dataFalse[5] = {1, 2, 3, 4, 5};
    ASSERT_FALSE( Task_7_33_run_squared_new( 5, dataFalse ) );
    int dataTrue[5] = {2, 2, 3, 4, 5};
    ASSERT_TRUE( Task_7_33_run_squared_new( 5, dataTrue ) );
    int dataTrueNotSort[5] = {2, 1, 3, 2, 5};
    ASSERT_TRUE( Task_7_33_run_squared_new( 5, dataTrueNotSort ) );
    dataFalse[0] = 5;
    dataFalse[1] = 4;
    dataFalse[2] = 3;
    dataFalse[3] = 2;
    dataFalse[4] = 1;
    ASSERT_FALSE( Task_7_33_run_squared_new( 5, dataFalse ) );
}
