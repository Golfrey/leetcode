/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        s.push({0, -1});
        int ret = 0;
        for (int i = 0; i < heights.size(); i++) {
            if(heights[i] >= s.top().first)
                s.push({heights[i], i});
            else {
                int plus = 0;
                while (!s.empty() && heights[i] < s.top().first) {
                    int val = s.top().first, index = s.top().second;
                    s.pop();
                    ret = max(ret, val * (index - s.top().second + plus));
                    plus = index - s.top().second + plus;
                }
                s.push({heights[i], i});
            }
        }
        int plus = 0;
        while (s.size() > 1) {
            int val = s.top().first, index = s.top().second;
            s.pop();
            ret = max(ret, val * (index - s.top().second + plus));
            plus = index - s.top().second + plus;
        }
        return ret;
    }
};
// @lc code=end

