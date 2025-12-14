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

TEST(leetcode, bfs)
{
    vector<std::vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    Solution sol;
    EXPECT_EQ(sol.canVisitAllRooms(rooms), false);
    auto rlt = sol.findAnagrams("cbaebabacd", "abc");
    for (auto num : rlt)
    {
        std::cout << num << std::endl;
    }
}

TEST(leetcode, test2)
{
    Solution sol;
    vector<int> sample{3, 2, 1, 5, 6, 4};
    EXPECT_EQ(sol.findKthLargest(sample, 2), 5);
    vector<int> list{1, 2, 3};
    auto rlt = sol.permute(list);
    EXPECT_EQ(sol.removeDuplicateLetters("bbcaac"), "bac");
    auto rlt2 = sol.combine(4, 2);
    std::cout << "hello world" << std::endl;
}
} // namespace leetcode