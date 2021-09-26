/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto num : nums)
            ret ^= num;
        return ret;
    }
};
// @lc code=end

