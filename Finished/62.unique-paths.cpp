/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[m][n] = dp[m][n-1] + dp[m-1][n]
        // dp[0][0] = 1
        if(m == 1)
            return 1;
        vector<int> dp1(n, 1);
        vector<int> dp2(n);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //cout << i << " " << j;
                dp2[j] = dp1[j] + (j - 1 >= 0 ? dp2[j - 1] : 0);
            }
            dp1 = dp2;
        }
        return dp2[n - 1];
    }
};
// @lc code=end

