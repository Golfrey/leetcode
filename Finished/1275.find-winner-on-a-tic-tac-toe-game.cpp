/*
 * @lc app=leetcode id=1275 lang=cpp
 *
 * [1275] Find Winner on a Tic Tac Toe Game
 */

// @lc code=start
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> aRow(3), bRow(3), aCol(3), bCol(3);
        int aD1 = 0, aD2 = 0, bD1 = 0, bD2 = 0;
        int index = 0;
        for (int i = 0; i < moves.size(); i++) {
            int x = moves[i][0], y = moves[i][1];
            if(i % 2 == 0) {
                if (++aRow[x] == 3 || ++aCol[y] == 3 || x == y && ++aD1 == 3 ||
                        x + y == 2 && ++aD2 == 3)
                    return "A";
            }
            else {
                if (++bRow[x] == 3 || ++bCol[y] == 3 || x == y && ++bD1 == 3 ||
                        x + y == 2 && ++bD2 == 3)
                    return "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
// @lc code=end

