/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(m == 1) {
            for (int i = 0; i < n; i++) {
                if(obstacleGrid[0][i] == 1)
                    return 0;
            }
            return 1;
        }
        vector<int> dp1(n);
        dp1[0] = !obstacleGrid[0][0];
        for (int i = 1; i < n; i++) {
            dp1[i] = dp1[i - 1] & (!obstacleGrid[0][i]);
        }
        vector<int> dp2(n);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //cout << i << " " << j;
                if(obstacleGrid[i][j] == 1)
                    dp2[j] = 0;
                else
                    dp2[j] = dp1[j] + (j - 1 >= 0 ? dp2[j - 1] : 0);
            }
            dp1 = dp2;
        }
        return dp2[n - 1];
    }
};
// @lc code=end

