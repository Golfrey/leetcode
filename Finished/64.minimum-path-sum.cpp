/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[m][n] = grid[m][n] + min(dp[m-1][n], dp[m][n-1])
        int m = grid.size(), n = grid[0].size();
        vector<int> dp1(n), dp2(n);
        for (int i = 0; i < n; i++)
            dp1[i] = (i > 0 ? dp1[i - 1] : 0) + grid[0][i];
        if(m == 1)
            return dp1[n - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0)
                    dp2[j] = grid[i][j] + min(dp2[j - 1], dp1[j]);
                else
                    dp2[j] = grid[i][j] + dp1[j];
            }
            dp1 = dp2;
        }
        return dp2[n - 1];
    }
};
// @lc code=end

