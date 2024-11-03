#include "ch2_01.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
// 自定义类的比较
TEST(ch2_01, test_1)
{
    TestClass t1{3}, t2{4};
    EXPECT_EQ(true, t2 > t1);
}

//内置类的比较
TEST(ch2_01, test_2)
{
    double a{0.3434f}, b{-0.3434f};
    EXPECT_EQ(true, a > b);
}
