/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        vector<int> ret(rowIndex + 1);
        row[0] = 1;
        for (int i = 0; i <= rowIndex; i++) {
            ret[0] = ret[i] = 1;
            for (int j = 1; j < i; j++)
                ret[j] = row[j - 1] + row[j];
            row = ret;
        }
        return ret;
    }
};
// @lc code=end

