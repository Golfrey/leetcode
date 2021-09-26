/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (int c : nums) {
            int ta = (~a & b & c) | (a & ~b & ~c);
            b = (~a & ~b & c) | (~a & b & ~c);
            a = ta;
        }
        return b;
    }
};
// @lc code=end

