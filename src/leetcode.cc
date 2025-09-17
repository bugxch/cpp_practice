#include "leetcode.h"

namespace leetcode
{

std::vector<std::string> Solution::letterCombinations(std::string digits)
{
    return {};
}


int Solution::trap(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int res = 0;
    int leftMax = height[left];
    int rightMax = height[right];
    while (left < right)
    {
        leftMax = std::max(height[left], leftMax);
        rightMax = std::max(height[right], rightMax);
        if (leftMax < rightMax)
        {
            res += leftMax - height[left];
            left++;
        }
        else
        {
            res += rightMax - height[right];
            right--;
        }
    }
    return res;
}

int Solution::trap2(vector<int> &height)
{
    vector<tuple<int, int>> stack; // <idx, value> pair
    int res = 0;
    for (int i = 0; i < height.size(); ++i)
    {
        while (!stack.empty() && height[i] > std::get<1>(stack.back()))
        {
            auto backEle = stack.back();
            stack.pop_back();
            if (stack.empty())
                break;
            res += (i - std::get<0>(backEle) - 1) *
                   std::min(height[i], std::get<1>(stack.back()));
        }
        stack.emplace_back(i, height[i]);
    }
    return res;
}
} // namespace leetcode