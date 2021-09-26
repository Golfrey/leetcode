/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i]; // num should be in nums[num-1]
            while(nums[num-1] != num) {
                int p = nums[num-1];
                nums[num-1] = num;
                num = p;
            }
        }
        vector<int> ret;
        for(int i=0; i<nums.size(); i++)
            if(nums[i]!=i+1) ret.push_back(i+1);
        return ret;
    }
};
// @lc code=end

