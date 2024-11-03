#include "ch2_02.h"
#include "gtest/gtest.h"


// This test case verifies the functionality of the fully specialized TC<int, int> class.
// It checks whether the functtest1() and functtest2() methods output the expected messages.
TEST(ch2_02, case00)
{
    TC<int, int> tc; // 这是泛化之后生成的一个新类型，所以没有m_stc静态成员
    tc.functtest1();
    tc.functtest2();
}


// This test case verifies the functionality of the partially specialized TC<double, float> class.
// It checks whether the functtest1() method outputs the expected message.
TEST(ch2_02, case01)
{
    TC<double, float> tc;
    tc.functtest1();
}

// This test case verifies the functionality of the fully specialized TC<float, int> class.
// It checks whether the functtest1() method outputs the expected message.
TEST(ch2_02, case02)
{
    TC<float, int> tc;
    tc.functtest1();
}

TEST(ch2_02, case03)
{
    TC<int, double> tc;
    // functtest1()是泛化版本的
    tc.functtest1();
    // m_stc是全特化版本的
    EXPECT_EQ(tc.m_stc, 120);
}