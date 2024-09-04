#include "gtest/gtest.h"
#include <iostream>
#include <string>

TEST(Item1, Test1) {
	EXPECT_EQ(1, 1);
}

TEST(Item1, Test2) {
	EXPECT_EQ(3, 1 + 2);
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}