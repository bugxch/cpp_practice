#include "leetcode.h"
#include "gtest/gtest.h"


namespace leetcode
{

TEST(leetcode, jieyushui)
{
    std::vector<int> height = {4, 2, 3, 4};
    Solution sol;
    EXPECT_EQ(sol.trap(height), 3);
}
} // namespace leetcode