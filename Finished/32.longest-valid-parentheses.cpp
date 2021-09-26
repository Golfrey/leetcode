/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
   int longestValidParentheses(string str) {
      int n = str.size();
      stack<pair<char, int>> s;
      for (int i = 0; i < n; i++) {
         if (str[i] == '(')
            s.push({'(', i});
         else if (str[i] == ')' && !s.empty() && s.top().first == '(')
            s.pop();
         else
            s.push({')', i});
      }
      int pre = n - 1, ret = 0;
      if (s.empty())
         return n;
      while(!s.empty()) {
         ret = max(ret, pre - s.top().second);
         pre = s.top().second - 1;
         s.pop();
      }
      ret = max(ret, pre - 0 + 1);
      return ret;
   }
};
// @lc code=end

