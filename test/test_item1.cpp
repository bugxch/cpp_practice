#include "item1.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

TEST(Item1, Test1)
{
    EXPECT_EQ(1, 1);
}

TEST(Item1, Test3)
{
    Item1 item;
    EXPECT_LE(6.0f, item.GetArea());
}