/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> chain;
        chain.push_back(pairs[0]);
        for (int i = 1; i < pairs.size(); i++) {
            if(pairs[i][0] > chain.back()[1]) {
                chain.push_back(pairs[i]);
            }
            else if(pairs[i][1] < chain.back()[1]) {
                chain.pop_back();
                chain.push_back(pairs[i]);
            }
        }
        return (int)chain.size();
    }
};
// @lc code=end

