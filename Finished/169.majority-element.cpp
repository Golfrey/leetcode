/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret, count = 0;
        for(auto num : nums) {
            if(count == 0){
                ret = num;
            count++;
        }
            else if (num == ret) count++;
            else
                count--;
            //cout << count;
        }
        return ret;
    }
};
// @lc code=end

