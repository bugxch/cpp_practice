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

vector<int> Solution::twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> umap;
    for (auto i = 0; i < nums.size(); i++)
    {
        if (umap.count(target - nums[i]) > 0)
        {
            return std::vector<int>{i, umap[target - nums[i]]};
        }
        umap.insert({nums[i], i});
    }
    return {};
}

int Solution::lengthOfLongestSubstring(string s)
{
    int ans = 0;
    int left = 0;
    int right = 0;
    unordered_map<char, int> table;
    while (right < s.size())
    {
        auto rch = s[right];
        right++;

        while (table.count(rch) > 0 && table[rch] > 0)
        {
            auto lch = s[left];
            left++;
            table[lch]--;
        }
        table[rch]++;
        ans = std::max(ans, right - left);
    }
    return ans;
}
} // namespace leetcode