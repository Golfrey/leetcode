/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int pre = -1, n = s.size(), ret = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                ret = (i - pre - 1) != 0 ? i - pre - 1 : ret;
                pre = i;
            }
        }
        return (n - pre - 1) != 0 ? n - pre - 1 : ret;
    }
};
// @lc code=end

