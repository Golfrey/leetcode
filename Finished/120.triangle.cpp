/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // dp2[j] = triangle[i][j] + max(dp1[j], dp1[j-1])
        int n = triangle.size();
        vector<int> dp1(n), dp2(n);
        dp2[0] = dp1[0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0)
                    dp2[j] = triangle[i][j] + dp1[j];
                else if(j==i)
                    dp2[j] = triangle[i][j] + dp1[j - 1];
                else
                    dp2[j] = triangle[i][j] + min(dp1[j], dp1[j - 1]);
                //cout << dp2[j] << endl;
            }
            dp1 = dp2;
        }
        return *min_element(dp2.begin(), dp2.end());
    }
};
// @lc code=end

