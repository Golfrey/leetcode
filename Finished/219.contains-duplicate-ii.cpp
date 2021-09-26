/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            if(umap.find(nums[i]) == umap.end())
                umap[nums[i]] = i;
            else {
                if (i - umap[nums[i]] <= k) {
                    //cout << i << " " << umap[nums[i]] << endl;
                    return true;
                }
                else umap[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end

