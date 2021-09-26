/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string& s) {
        string::iterator it1, it2;
        for (it1 = s.begin(), it2 = --s.end(); it1 < it2; it1++, it2--) {
            if(*it1 != *it2)
                return false;
        }
        return true;
    }

    void backtrace(string s, )

    vector<vector<string>> partition(string s) {
        
    }
};
// @lc code=end

