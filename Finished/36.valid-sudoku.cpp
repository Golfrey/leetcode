/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //
        vector<vector<int>> used1(9, vector<int>(9)), used2(9, vector<int>(9)),
            used3(9, vector<int>(9));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board.size(); j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
            }
        return true;
    }
};
// @lc code=end

