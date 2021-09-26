/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        //cout << n << endl;
        unsigned int ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            int j = columnTitle[n-1-i] - 'A' + 1;
            //cout << pow(26, 0);
            ret += (unsigned int)pow(26, i) * j;
            //cout<<ret<<endl;
        }
        return ret;
    }
};
// @lc code=end

