// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem90.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    void backtrace(vector<vector<int>>& ret, vector<int>& nums, vector<int>& path, int index) {
        int n = nums.size();
        if(index == n) {
            ret.push_back(path);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[index]);
            backtrace(ret, nums, path, i+1);
            path.pop_back();
            int p = i + 1;
            while(p < nums.size() && nums[p] == nums[p-1])
                p++;
            backtrace(ret, nums, path, p);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret = {};
        vector<int> path = {};
        backtrace(ret, nums, path, 0);
        return ret;
    }
};
// @lc code=end

