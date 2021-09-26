/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>&nums, int i, int j) {
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        rotate(nums, 0, nums.size() - 1);
        rotate(nums, 0, k - 1);
        rotate(nums, k, nums.size() - 1);
    }
};
// @lc code=end

