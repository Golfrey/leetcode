// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem516.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n));
        for (int i = 0; i < n; i++)
            dp[1][i] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < n - i + 1; j++) {
                dp[i][j] = (s[j] == s[i + j - 1])
                               ? (2 + dp[i - 2][j + 1])
                               : max(dp[i - 1][j], dp[i - 1][j + 1]);
            }
        return dp[n][0];
    }
};
// @lc code=end

