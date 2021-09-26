/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size() - 1;
        int leftLeft, leftRight = n, rightLeft = 0, rightRight = n, left, right;
        while(leftLeft <= leftRight) {
            int mid = leftLeft + (leftRight - leftLeft) / 2;
            if(intervals[mid][0] == newInterval[0]) {
                left = mid;
                break;
            }
            else if(intervals[mid][0] > newInterval[0])
                leftLeft = mid + 1;
            else if(intervals[mid][0] < newInterval[0])
                leftRight = mid - 1;
        }
        while(rightLeft <= rightRight) {
            int mid = rightLeft + (rightRight - rightLeft) / 2;
            if(intervals[mid][0] == newInterval[0]) {
                right = mid;
                break;
            }
            else if(intervals[mid][0] > newInterval[0])
                rightLeft = mid + 1;
            else if(intervals[mid][0] < newInterval[0])
                rightRight = mid - 1;
        }
        if(leftLeft > leftRight)
            left = leftRight;
        if(rightLeft > rightRight)
            right = rightRight;
        
    }
};
// @lc code=end

