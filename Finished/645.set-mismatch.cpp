/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret(2);
        for (int i : nums) {
            if (nums[abs(i) - 1] < 0)
                ret[0] = abs(i);
            else
                nums[abs(i) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                ret[1] = i + 1;
        }
        return ret;
    }
};
// @lc code=end

