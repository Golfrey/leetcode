/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        /*
        1 26
        2 676
        3 17576
        4 456976
        5 11881376
        6 308915776
        */
        string res;

    char tmp;

    while(n){

        n -= 1;

        tmp = 'A' + n % 26;

        res = tmp + res;

        n /= 26;

    }

    return res;

    }
};
// @lc code=end

