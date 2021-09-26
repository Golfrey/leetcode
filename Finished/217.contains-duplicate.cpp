/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (auto i : nums) {
            if(us.find(i) != us.end())
                return true;
            us.insert(i);
        }
        return false;
    }
};
// @lc code=end

