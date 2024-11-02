#include "ch2.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

TEST(CH2, test_2_1)
{
    EXPECT_EQ(sub_fun(4, 3), 1);
}

TEST(CH2, test_2_2)
{
    MyVector<int> tmpvec;
    tmpvec.myfunc();
}

TEST(CH2, test_2_3)
{
    MyVector<string>::mystaticfunc();
}
