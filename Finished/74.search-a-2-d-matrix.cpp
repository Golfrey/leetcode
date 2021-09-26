/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        int line = right >= 0 ? right : 0;
        left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[line][mid] == target)
                return true;
            else if(matrix[line][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
// @lc code=end

