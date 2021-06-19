#include "tests.h"

TEST( Task7_33, run )
{
    int dataFalse[5] = {1, 2, 3, 4, 5};
    ASSERT_FALSE( Task_7_33_run( dataFalse, 5  ) );
    int dataTrue[5] = {2, 2, 3, 4, 5};
    ASSERT_TRUE( Task_7_33_run( dataTrue, 5 ) );
    int dataTrueNotSort[5] = {1, 2, 2, 3, 4};
    ASSERT_TRUE( Task_7_33_run(  dataTrueNotSort, 5 ) );
    dataFalse[0] = 5;
    dataFalse[1] = 4;
    dataFalse[2] = 3;
    dataFalse[3] = 2;
    dataFalse[4] = 1;
    ASSERT_FALSE( Task_7_33_run( dataFalse, 5 ) );
}

TEST( Task7_33_s_p, run )
{
    int dataFalse[5] = {1, 2, 3, 4, 5};
    ASSERT_FALSE( Task_7_33_run_s_p( dataFalse   ) );
    int dataTrue[5] = {2, 2, 3, 4, 5};
    ASSERT_TRUE( Task_7_33_run_s_p( dataTrue  ) );
    int dataTrueNotSort[5] = {2, 2, 1, 3, 2};
    ASSERT_TRUE( Task_7_33_run_s_p( dataTrueNotSort ) );
    dataFalse[0] = 5;
    dataFalse[1] = 4;
    dataFalse[2] = 3;
    dataFalse[3] = 2;
    dataFalse[4] = 1;
    ASSERT_FALSE( Task_7_33_run_s_p( dataFalse  ) );
}
