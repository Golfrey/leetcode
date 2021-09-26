/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // 1 2 3 4 5 6 7
        // dp[1] = 1
        // dp[n] = for(int i=0; i<n; i++) for every element make root, dp[i-1] + dp[n-i-1]
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        return dp[n];
    }
};
// @lc code=end

