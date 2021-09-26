/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j] to be the number of distinct subsequences of t[0..i-1] in s[0..j-1]
        // dp[i][j] = dp[i][j-1] if t[i-1] != s[j-1]
        // dp[i][j] = dp[i][j-1] + dp[i-1][j-1] if t[i-1] == s[j-1] 
        // dp[0][j] = 1 for all j
        // dp[i][0] = 0 for all i
        int m = t.length(), n = s.length();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1));
        for (int j = 0; j <= n; j++)
            dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++) {
                dp[i][j] = dp[i][j - 1] +
                           (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        return dp[m][n];
    }
};
// @lc code=end

