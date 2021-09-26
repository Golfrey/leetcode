/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string ret = "";
        list<int> numbers;
        for (int i = 1; i <= n; i++)
            numbers.push_back(i);
        vector<int> factVal = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        k--;
        for (int i = 1; i <= n; i++) {
            int index = k / factVal[n - i];
            list<int>::iterator it = numbers.begin();
            advance(it, index);
            ret += to_string(*it);
            numbers.erase(it);
            k -= index * factVal[n - i];
        }
        return ret;
    }
};
// @lc code=end

