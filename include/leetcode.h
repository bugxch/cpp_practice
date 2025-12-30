/*************  ✨ Windsurf Command ⭐  *************/
#ifndef LEETCODE_H
#define LEETCODE_H

#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

namespace leetcode
{
class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string digits);
    int trap(vector<int> &height);
    int trap2(vector<int> &height);
    vector<int> twoSum(vector<int> &nums, int target);
    int lengthOfLongestSubstring(string s); // 无重复字符的最长子串
    int findKthLargest(vector<int> &nums, int k);
    bool hasCycle(ListNode *head); // 环形链表
    ListNode *mergeTwoLists(ListNode *list1,
                            ListNode *list2); // 合并两个有序链表
    bool canVisitAllRooms(vector<vector<int>> &rooms); // 是否可以访问所有的房间
    vector<int> findAnagrams(string s, string p); // 所有的字母异位词
    ListNode *removeNthFromEnd(ListNode *head, int n); // 删除链表倒数第n个节点
    vector<vector<int>> permute(vector<int> &nums); // 全排列
    string removeDuplicateLetters(string s);        // 去除重复字母
    vector<vector<int>> subsets(vector<int> &nums); // 求所有子集
    vector<vector<int>> combine(int n, int k);      // 组合
    vector<string> generateParenthesis(int n);      // 括号生成
    void merge(vector<int> &nums1,
               int m,
               vector<int> &nums2,
               int n);                              // 合并有序链表
    vector<int> rightSideView(TreeNode *root);      // 二叉树的右视图
    int removeElement(vector<int> &nums, int val);  // 移除元素
    vector<vector<int>> levelOrder(TreeNode *root); // 二叉树的层序遍历
    vector<int> preorderTraversal(TreeNode *root);  // 二叉树的前序遍历
    int removeDuplicates(vector<int> &nums); // 删除有序数组中的重复项
    int longestConsecutive(vector<int> &nums);          // 最长连续子序列
    int lengthOfLIS(vector<int> &nums);                 // 最长递增子序列
    int coinChange(vector<int> &coins, int amount);     // 零钱兑换
    int minFallingPathSum(vector<vector<int>> &matrix); // 最小下降路径和
    int numDistinct(string s, string t);                // 不同的子序列
    int numSquares(int n);                              // 完全平方数
};
} // namespace leetcode

#endif // LEETCODE_H