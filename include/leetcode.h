/*************  ✨ Windsurf Command ⭐  *************/
#ifndef LEETCODE_H
#define LEETCODE_H

#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
namespace leetcode
{
class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string digits);
    int trap(vector<int> &height);
    int trap2(vector<int> &height);
    vector<int> twoSum(vector<int> &nums, int target);
    int lengthOfLongestSubstring(string s);
    int findKthLargest(vector<int> &nums, int k);
};

} // namespace leetcode

#endif // LEETCODE_H
       /*******  0c16a835-1f49-4387-b3f9-c37209e7418f  *******/