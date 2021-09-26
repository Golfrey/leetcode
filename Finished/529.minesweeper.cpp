/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
private:
    int isMine(vector<vector<char>>& board, int x, int y) {
        if(x < 0 || x > board.size() - 1 || y < 0 || y > board[0].size() - 1)
            return 0;
        return board[x][y] == 'M';
    }

    int calculateMine(vector<vector<char>>& board, int x, int y) {
        if(x < 0 || x > board.size() - 1 || y < 0 || y > board[0].size() - 1)
            return 0;
        return isMine(board, x - 1, y) + isMine(board, x, y - 1) +
               isMine(board, x + 1, y) + isMine(board, x, y + 1) +
               isMine(board, x + 1, y + 1) + isMine(board, x - 1, y - 1) +
               isMine(board, x + 1, y - 1) + isMine(board, x - 1, y + 1);
    }

public:
    void updateBoard(vector<vector<char>>& board, int x, int y) 
    {
        if(x < 0 || x > board.size() - 1 || y < 0 || y > board[0].size() - 1)
            return;
        if(board[x][y] == 'B' || board[x][y] >= '1' && board[x][y] <= '8')
            return;
        int mNum = calculateMine(board, x, y);
        if(mNum > 0)
            board[x][y] = mNum + '0';
        else {
            board[x][y] = 'B';
            updateBoard(board, x - 1, y);
            updateBoard(board, x, y - 1);
            updateBoard(board, x + 1, y);
            updateBoard(board, x, y + 1);
            updateBoard(board, x + 1, y + 1);
            updateBoard(board, x - 1, y - 1);
            updateBoard(board, x + 1, y - 1);
            updateBoard(board, x - 1, y + 1);
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        int x = click[0], y = click[1];
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int mNum = calculateMine(board, click[0], click[1]);
        if(mNum > 0)
            board[click[0]][click[1]] = mNum + '0';
        else {
            board[x][y] = 'B';
            updateBoard(board, x - 1, y);
            updateBoard(board, x, y - 1);
            updateBoard(board, x + 1, y);
            updateBoard(board, x, y + 1);
            updateBoard(board, x + 1, y + 1);
            updateBoard(board, x - 1, y - 1);
            updateBoard(board, x + 1, y - 1);
            updateBoard(board, x - 1, y + 1);
        }
        return board;
    }
};
// @lc code=end

