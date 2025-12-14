#include "leetcode.h"
#include <algorithm>

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

int Solution::findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, less<int>> myQ;
    for (auto num : nums)
    {
        myQ.push(num);
    }
    int cnt = 0;
    while (cnt < k - 1)
    {
        myQ.pop();
        cnt++;
    }
    return myQ.top();
}

bool Solution::hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != fast)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

ListNode *Solution::mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
    {
        return list2;
    }
    else if (list2 == nullptr)
    {
        return list1;
    }
    else if (list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
}

bool Solution::canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    int num = 0;
    vector<bool> visited(n, false);
    std::queue<int> myQ;
    myQ.push(0);
    visited[0] = true;
    while (!myQ.empty())
    {
        int qSize = myQ.size();
        for (int i = 0; i < qSize; ++i)
        {
            int curIdx = myQ.front();
            myQ.pop();
            num += 1;
            for (auto room : rooms[curIdx])
            {
                if (!visited[room])
                {
                    myQ.push(room);
                    visited[room] = true;
                }
            }
        }
    }
    return num == n;
}
vector<int> Solution::findAnagrams(string s, string p)
{
    vector<int> rlt;
    int left = 0;
    int right = 0;
    unordered_map<char, int> need;
    unordered_map<char, int> window;

    for (auto ch : p)
    {
        need[ch]++;
    }

    while (right < s.size())
    {
        auto rch = s[right];
        right++;
        window[rch]++;

        while (right - left > p.size())
        {
            auto lch = s[left];
            window[lch]--;
            if (window[lch] == 0)
            {
                window.erase(lch);
            }
            left++;
        }

        if (need == window)
        {
            rlt.emplace_back(left);
        }
    }

    return rlt;
}

ListNode *Solution::removeNthFromEnd(ListNode *head, int n)
{
    stack<ListNode *> st;
    ListNode dummyNode = ListNode(0);
    dummyNode.next = head;

    ListNode *cur = &dummyNode;
    while (cur != nullptr)
    {
        st.push(cur);
        cur = cur->next;
    }

    int cnt = 0;
    ListNode *prevNode = nullptr;
    while (cnt < n)
    {
        prevNode = st.top();
        st.pop();
        cnt++;
    }
    st.top()->next = prevNode->next;
    return dummyNode.next;
}

void dfs(vector<int> &curPath,
         const vector<int> &nums,
         vector<bool> &visited,
         vector<vector<int>> &rlt)
{
    // reach the leaf node
    if (curPath.size() == nums.size())
    {
        rlt.emplace_back(curPath);
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (visited[i])
        {
            continue;
        }
        visited[i] = true;
        curPath.emplace_back(nums[i]);
        dfs(curPath, nums, visited, rlt);
        visited[i] = false;
        curPath.pop_back();
    }
}


vector<vector<int>> Solution::permute(vector<int> &nums)
{
    vector<vector<int>> rlt;
    vector<bool> visited(nums.size(), false);
    vector<int> curPath;
    dfs(curPath, nums, visited, rlt);
    return rlt;
}

string Solution::removeDuplicateLetters(string s)
{
    bool isInQueue[26] = {false};
    int alphaCnt[26] = {0};

    for (auto ch : s)
    {
        alphaCnt[ch - 'a']++;
    }

    vector<char> myQ;
    for (auto ch : s)
    {
        if (isInQueue[ch - 'a'])
        {
            alphaCnt[ch - 'a']--;
            continue;
        }

        while (!myQ.empty() && ch < myQ.back() &&
               alphaCnt[myQ.back() - 'a'] > 0)
        {
            isInQueue[myQ.back() - 'a'] = false;
            myQ.pop_back();
        }

        myQ.emplace_back(ch);
        isInQueue[ch - 'a'] = true;
        alphaCnt[ch - 'a']--;
    }
    string rlt;
    // get the result
    for (auto ch : myQ)
    {
        rlt += ch;
    }
    return rlt;
}

void dfs(vector<int> &curPath,
         int startIdx /*explore start idx*/,
         const vector<int> &nums,
         vector<vector<int>> &res)
{
    res.emplace_back(curPath);
    for (int start = startIdx; start < nums.size(); start++)
    {
        curPath.emplace_back(nums[start]);
        dfs(curPath, start + 1, nums, res);
        curPath.pop_back();
    }
}

vector<vector<int>> Solution::subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> curPath;
    dfs(curPath, 0, nums, res);
    return res;
}

void helper(vector<int> &curPath,
            int startIdx /*explore start idx*/,
            const int n,
            const int k,
            vector<vector<int>> &res)
{
    if (curPath.size() == k)
    {
        res.emplace_back(curPath);
        return;
    }

    for (int start = startIdx; start <= n; start++)
    {
        curPath.emplace_back(start);
        helper(curPath, start + 1, n, k, res);
        curPath.pop_back();
    }
}

vector<vector<int>> Solution::combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> curPath;
    helper(curPath, 1, n, k, res);
    return res;
}

} // namespace leetcode