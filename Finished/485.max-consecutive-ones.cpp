/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int pre = -1;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                ret = max(ret, i - pre - 1);
                pre = i;
            }
        }
        return max(ret, n - pre - 1);
    }
};
// @lc code=end

