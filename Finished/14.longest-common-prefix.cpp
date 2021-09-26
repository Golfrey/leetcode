/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)
            return strs[0];
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs[strs.size() - 1];
        int i = 0;
        for (; i < a.size() && i < b.size(); i++) {
            if(a[i] != b[i])
                break;
        }
        return a.substr(0, i);
    }
};
// @lc code=end

