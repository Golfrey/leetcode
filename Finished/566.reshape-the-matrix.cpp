/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int>> ret(r, vector<int>(c));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                // i j = i * m + j th element
                // (i*m+j) / m
                int x = (i * n + j) / c, y = (i * n + j) % c;
                //cout << x << ' ' << y << endl;
                ret[x][y] = mat[i][j];
            }
        return ret;
    }
};
// @lc code=end

