#include "leetcode.h"
#include <algorithm>

namespace leetcode {

std::vector<std::string> Solution::letterCombinations(std::string digits) {
    return {};
}


int Solution::trap(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int res = 0;
    int leftMax = height[left];
    int rightMax = height[right];
    while (left < right) {
        leftMax = std::max(height[left], leftMax);
        rightMax = std::max(height[right], rightMax);
        if (leftMax < rightMax) {
            res += leftMax - height[left];
            left++;
        } else {
            res += rightMax - height[right];
            right--;
        }
    }
    return res;
}

int Solution::trap2(vector<int> &height) {
    vector<tuple<int, int>> stack; // <idx, value> pair
    int res = 0;
    for (int i = 0; i < height.size(); ++i) {
        while (!stack.empty() && height[i] > std::get<1>(stack.back())) {
            auto backEle = stack.back();
            stack.pop_back();
            if (stack.empty())
                break;
            res += (i - std::get<0>(backEle) - 1) * std::min(height[i], std::get<1>(stack.back()));
        }
        stack.emplace_back(i, height[i]);
    }
    return res;
}

vector<int> Solution::twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> umap;
    for (auto i = 0; i < nums.size(); i++) {
        if (umap.count(target - nums[i]) > 0) {
            return std::vector<int>{i, umap[target - nums[i]]};
        }
        umap.insert({nums[i], i});
    }
    return {};
}

int Solution::lengthOfLongestSubstring(string s) {
    int rlt = 0;
    int left = 0;
    int right = 0;
    unordered_map<char, int> umap;

    while (right < s.size()) {
        auto rch = s[right];
        umap[rch]++;
        right++;

        while (umap[rch] > 1) {
            auto lch = s[left];
            left++;
            umap[lch]--;
            if (umap[lch] == 0) {
                umap.erase(lch);
            }
        }
        rlt = std::max(rlt, right - left);
    }
    return rlt;
}

int Solution::findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, less<int>> myQ;
    for (auto num : nums) {
        myQ.push(num);
    }
    int cnt = 0;
    while (cnt < k - 1) {
        myQ.pop();
        cnt++;
    }
    return myQ.top();
}

bool Solution::hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != fast) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

ListNode *Solution::mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) {
        return list2;
    } else if (list2 == nullptr) {
        return list1;
    } else if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
}

bool Solution::canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    int num = 0;
    vector<bool> visited(n, false);
    std::queue<int> myQ;
    myQ.push(0);
    visited[0] = true;
    while (!myQ.empty()) {
        int qSize = myQ.size();
        for (int i = 0; i < qSize; ++i) {
            int curIdx = myQ.front();
            myQ.pop();
            num += 1;
            for (auto room : rooms[curIdx]) {
                if (!visited[room]) {
                    myQ.push(room);
                    visited[room] = true;
                }
            }
        }
    }
    return num == n;
}
vector<int> Solution::findAnagrams(string s, string p) {
    vector<int> rlt;
    int left = 0;
    int right = 0;
    unordered_map<char, int> need;
    unordered_map<char, int> window;

    for (auto ch : p) {
        need[ch]++;
    }

    while (right < s.size()) {
        auto rch = s[right];
        right++;
        window[rch]++;

        while (right - left > p.size()) {
            auto lch = s[left];
            window[lch]--;
            if (window[lch] == 0) {
                window.erase(lch);
            }
            left++;
        }

        if (need == window) {
            rlt.emplace_back(left);
        }
    }

    return rlt;
}

ListNode *Solution::removeNthFromEnd(ListNode *head, int n) {
    stack<ListNode *> st;
    ListNode dummyNode = ListNode(0);
    dummyNode.next = head;

    ListNode *cur = &dummyNode;
    while (cur != nullptr) {
        st.push(cur);
        cur = cur->next;
    }

    int cnt = 0;
    ListNode *prevNode = nullptr;
    while (cnt < n) {
        prevNode = st.top();
        st.pop();
        cnt++;
    }
    st.top()->next = prevNode->next;
    return dummyNode.next;
}

void dfs(vector<int> &curPath, const vector<int> &nums, vector<bool> &visited, vector<vector<int>> &rlt) {
    // reach the leaf node
    if (curPath.size() == nums.size()) {
        rlt.emplace_back(curPath);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        curPath.emplace_back(nums[i]);
        dfs(curPath, nums, visited, rlt);
        visited[i] = false;
        curPath.pop_back();
    }
}


vector<vector<int>> Solution::permute(vector<int> &nums) {
    vector<vector<int>> rlt;
    vector<bool> visited(nums.size(), false);
    vector<int> curPath;
    dfs(curPath, nums, visited, rlt);
    return rlt;
}

string Solution::removeDuplicateLetters(string s) {
    bool isInQueue[26] = {false};
    int alphaCnt[26] = {0};

    for (auto ch : s) {
        alphaCnt[ch - 'a']++;
    }

    vector<char> myQ;
    for (auto ch : s) {
        if (isInQueue[ch - 'a']) {
            alphaCnt[ch - 'a']--;
            continue;
        }

        while (!myQ.empty() && ch < myQ.back() && alphaCnt[myQ.back() - 'a'] > 0) {
            isInQueue[myQ.back() - 'a'] = false;
            myQ.pop_back();
        }

        myQ.emplace_back(ch);
        isInQueue[ch - 'a'] = true;
        alphaCnt[ch - 'a']--;
    }
    string rlt;
    // get the result
    for (auto ch : myQ) {
        rlt += ch;
    }
    return rlt;
}

void dfs(vector<int> &curPath, int startIdx /*explore start idx*/, const vector<int> &nums, vector<vector<int>> &res) {
    res.emplace_back(curPath);
    for (int start = startIdx; start < nums.size(); start++) {
        curPath.emplace_back(nums[start]);
        dfs(curPath, start + 1, nums, res);
        curPath.pop_back();
    }
}

vector<vector<int>> Solution::subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> curPath;
    dfs(curPath, 0, nums, res);
    return res;
}

void helper(vector<int> &curPath,
            int startIdx /*explore start idx*/,
            const int n,
            const int k,
            vector<vector<int>> &res) {
    if (curPath.size() == k) {
        res.emplace_back(curPath);
        return;
    }

    for (int start = startIdx; start <= n; start++) {
        curPath.emplace_back(start);
        helper(curPath, start + 1, n, k, res);
        curPath.pop_back();
    }
}

vector<vector<int>> Solution::combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> curPath;
    helper(curPath, 1, n, k, res);
    return res;
}

void helper2(vector<string> &rlt, string &curPath, const int n, int left, int right) {
    if (right < 0 || left < 0) {
        return;
    }

    if (left > right) {
        return;
    }


    if (right == 0 && left == 0) {
        rlt.push_back(curPath);
        return;
    }
    // handle left branch
    curPath += "(";
    helper2(rlt, curPath, n, left - 1, right);
    curPath.pop_back();

    // handle right branch
    curPath += ")";
    helper2(rlt, curPath, n, left, right - 1);
    curPath.pop_back();
}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> rlt;
    string curPath;
    helper2(rlt, curPath, n, n, n);
    return rlt;
}

void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> rlt;
    int left = 0;
    int right = 0;
    while (left < m && right < n) {
        if (nums1[left] < nums2[right]) {
            rlt.emplace_back(nums1[left]);
            left++;
        } else {
            rlt.emplace_back(nums2[right]);
            right++;
        }
    }

    if (left == m) {
        while (rlt.size() < m + n) {
            rlt.emplace_back(nums2[right++]);
        }
    }

    if (right == n) {
        while (rlt.size() < m + n) {
            rlt.emplace_back(nums1[left++]);
        }
    }

    nums1 = rlt;
}

vector<int> Solution::rightSideView(TreeNode *root) {
    vector<int> rlt;
    if (root == nullptr) {
        return rlt;
    }
    queue<TreeNode *> myQ;


    myQ.push(root);
    while (!myQ.empty()) {
        int qz = myQ.size();
        rlt.emplace_back(myQ.back()->val);
        for (int i = 0; i < qz; i++) {
            auto curNode = myQ.front();
            myQ.pop();
            // left branch
            if (curNode->left) {
                myQ.push(curNode->left);
            }
            // right
            if (curNode->right) {
                myQ.push(curNode->right);
            }
        }
    }
    return rlt;
}

int Solution::removeElement(vector<int> &nums, int val) {
    int slow = 0;
    int fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}


vector<vector<int>> Solution::levelOrder(TreeNode *root) {
    vector<vector<int>> rlt;
    if (root == nullptr) {
        return rlt;
    }
    queue<TreeNode *> myQ;
    myQ.push(root);
    while (!myQ.empty()) {
        int qz = myQ.size();
        vector<int> layerList;
        for (int i = 0; i < qz; i++) {
            auto curNode = myQ.front();
            layerList.push_back(curNode->val);
            myQ.pop();

            if (curNode->left) {
                myQ.push(curNode->left);
            }
            if (curNode->right) {
                myQ.push(curNode->right);
            }
        }
        rlt.push_back(layerList);
    }

    return rlt;
}


void dfs(vector<int> &rlt, TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    rlt.push_back(root->val);
    if (root->left) {
        dfs(rlt, root->left);
    }
    if (root->right) {
        dfs(rlt, root->right);
    }
}


vector<int> Solution::preorderTraversal(TreeNode *root) {
    vector<int> rlt;
    dfs(rlt, root);
    return rlt;
}

int Solution::removeDuplicates(vector<int> &nums) {
    int slow = 0;
    int fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}

int Solution::longestConsecutive(vector<int> &nums) {
    unordered_set<int> numSet;
    for (auto num : nums) {
        numSet.insert(num);
    }

    int maxLen = 0;
    for (auto num : numSet) {
        int curLen = 1;
        if (!numSet.count(num - 1)) {
            int startNum = num;
            while (numSet.count(startNum + 1)) {
                curLen++;
                startNum++;
            }
        }
        maxLen = std::max(maxLen, curLen);
    }

    return maxLen;
}

void LIShelper(vector<int> &curPath, const vector<int> nums, vector<bool> &visited, int &maxLen, int startIdx) {
    maxLen = maxLen > curPath.size() ? maxLen : curPath.size();

    for (int i = startIdx; i < nums.size(); i++) {
        if (visited[i]) {
            continue;
        }
        if ((!curPath.empty() && nums[i] > nums[curPath.back()]) || curPath.empty()) {
            visited[i] = true;
            curPath.push_back(i);
            LIShelper(curPath, nums, visited, maxLen, i);
            curPath.pop_back();
            visited[i] = false;
        }
    }
}

int Solution::lengthOfLIS(vector<int> &nums) {
    vector<bool> visted(nums.size(), false);
    vector<int> curPath;
    int maxLen = 1;
    LIShelper(curPath, nums, visted, maxLen, 0);
    return maxLen;
}

int Solution::coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i < amount + 1; i++) {
        for (auto coin : coins) {
            if (coin <= i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int Solution::minFallingPathSum(vector<vector<int>> &matrix) {
    int len = matrix.size();
    vector<vector<int>> dp(len, vector<int>(len, 66666));
    // init base case
    for (int j = 0; j < len; j++) {
        dp[0][j] = matrix[0][j];
    }

    for (int row = 1; row < len; row++) {
        for (int col = 0; col < len; col++) {
            int minVal = 66666;
            for (int j = -1; j < 2; j++) {
                if (col + j < 0 || col + j > len - 1) {
                    continue;
                }
                minVal = std::min(minVal, dp[row - 1][col + j]);
            }
            dp[row][col] = matrix[row][col] + minVal;
        }
    }
    return *min_element(dp[len - 1].begin(), dp[len - 1].end());
}

void numDistinctHelper(string s, string t, string &curStr, int startIdx, int &totalCnt) {
    if (curStr == t) {
        totalCnt++;
        return;
    }

    for (int i = startIdx; i < s.size(); i++) {
        string tmpStr = curStr + s[i];
        if (t.compare(0, tmpStr.length(), tmpStr) == 0) {
            curStr = tmpStr;
            numDistinctHelper(s, t, curStr, i + 1, totalCnt);
            curStr.pop_back();
        }
    }
}

int Solution::numDistinct(string s, string t) {
    int res = 0;
    string curStr;
    numDistinctHelper(s, t, curStr, 0, res);
    return res;
}

vector<int> Solution::spiralOrder(vector<vector<int>> &matrix) {
    vector<int> rlt;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return rlt;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> visited(row, vector<int>(col, false));
    constexpr int directions[4][2] = {{0, 1},   // turn righ
                                      {1, 0},   // turn down
                                      {0, -1},  // turn left
                                      {-1, 0}}; // turn up
    int rowIdx = 0;
    int colIdx = 0;
    int directIdx = 0;
    while (rlt.size() < row * col) {
        visited[rowIdx][colIdx] = true;
        rlt.emplace_back(matrix[rowIdx][colIdx]);
        int nextRow = rowIdx + directions[directIdx][0];
        int nextCol = colIdx + directions[directIdx][1];
        // calculate the next directions
        if (nextRow > row - 1 || nextRow < 0 || nextCol > col - 1 || nextCol < 0 || visited[nextRow][nextCol]) {
            // change the direction
            directIdx = (directIdx + 1) % 4;
        }
        rowIdx += directions[directIdx][0];
        colIdx += directions[directIdx][1];
    }
    return rlt;
}

int Solution::numSquares(int n) {
    vector<int> dp(n + 1, 0);
    int sqrtNum = std::sqrt(n);
    // init square data
    for (int i = 1; i <= sqrtNum; i++) {
        dp[i * i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (dp[i] == 1) {
            continue;
        }
        int minVal = n;
        for (int j = 1; j <= sqrtNum; j++) {
            if (i - j * j >= 0) {
                minVal = std::min(minVal, dp[i - j * j]);
            }
        }
        dp[i] = minVal + 1;
    }
    return dp[n];
}
void partitionStrHelper(vector<vector<string>> &rlt,
                        const string s,
                        vector<string> &curPath,
                        int startIdx,
                        const vector<vector<bool>> &isPalindrome) {
    if (startIdx == s.size()) {
        rlt.push_back(curPath);
        return;
    }

    for (int i = startIdx; i < s.size(); i++) {
        auto subStr = s.substr(startIdx, i - startIdx + 1);
        if (!isPalindrome[startIdx][i]) {
            continue;
        }
        curPath.push_back(subStr);
        partitionStrHelper(rlt, s, curPath, i + 1, isPalindrome);
        curPath.pop_back();
    }
}

vector<vector<string>> Solution::partitionStr(string s) {
    vector<vector<string>> rlt;
    int n = s.size();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
        if (i + 1 < n) {
            isPalindrome[i][i + 1] = (s[i] == s[i + 1]);
        }
    }

    for (int row = n - 2; row >= 0; row--) {
        for (int col = row + 2; col < n; col++) {
            if (s[row] == s[col]) {
                isPalindrome[row][col] = isPalindrome[row + 1][col - 1];
            }
        }
    }
    vector<string> curPath;
    partitionStrHelper(rlt, s, curPath, 0, isPalindrome);
    return rlt;
}

int Solution::longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                ans = max(ans, i - st.top());
            }
        }
    }
    return ans;
}

int Solution::maxLevelSum(TreeNode *root) {
    int layer = 1;
    int depth = 0;
    int maxSum = INT16_MIN;
    queue<TreeNode *> myQ;
    if (root == nullptr) {
        return 0;
    }
    myQ.push(root);
    while (!myQ.empty()) {
        int qz = myQ.size();
        int layerSum = 0;
        depth++;
        for (int i = 0; i < qz; i++) {
            auto node = myQ.front();
            myQ.pop();
            layerSum += node->val;
            if (node->left) {
                myQ.push(node->left);
            }
            if (node->right) {
                myQ.push(node->right);
            }
        }
        if (layerSum > maxSum) {
            maxSum = layerSum;
            layer = depth;
        }
    }

    return layer;
}

int GetPilotPos(vector<int> &nums, int start, int end) {
    // take end pos as pilot
    int pilot = end;
    int left = -1;
    int right = 0;
    while (right < end) {
        if (nums[right] <= nums[pilot]) {
            left++;
            swap(nums[right], nums[left]);
        }
        right++;
    }
    // swap left
    swap(nums[end], nums[left + 1]);
    return left + 1;
}
void mergeSortHelper(vector<int> &nums, int start, int end) {
    if (start < end) {
        int pilot = GetPilotPos(nums, start, end);
        mergeSortHelper(nums, start, pilot - 1);
        mergeSortHelper(nums, pilot + 1, end);
    }
}
void Solution::mergeSort(vector<int> &nums) {
    mergeSortHelper(nums, 0, nums.size() - 1);
}
} // namespace leetcode