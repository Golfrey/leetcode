/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH = -1, maxV = -1;
        int pre = 0;
        for(int i : horizontalCuts) {
            maxH = max(maxH, i - pre);
            pre = i;
        }
        maxH = max(maxH, h - horizontalCuts[horizontalCuts.size()-1]);
        pre = 0;
        for(int i : verticalCuts) {
            maxV = max(maxV, i - pre);
            pre = i;
        }
        maxV = max(maxV, w - verticalCuts[verticalCuts.size()-1]);
        return (int)((long)maxH*maxV%1000000007);
    }
};
// @lc code=end

