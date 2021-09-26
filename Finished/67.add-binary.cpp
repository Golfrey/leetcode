// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem67.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int aN = a.size() - 1, bN = b.size() - 1;
        vector<int> num;
        string ret = "";
        int carry = 0;
        while (aN >= 0 || bN >= 0) {
            //cout << aN << bN;
            int i = (aN < 0 ? 0 : a[aN--] - '0') +
                    (bN < 0 ? 0 : b[bN--] - '0') + carry;
            if (i >= 2) {
                i %= 2;
                carry = 1;
            } else
                carry = 0;
            num.push_back(i);
        }
        if(carry == 1)
            num.push_back(1);
        int n = num.size() - 1;
        for (int i = n; i >= 0; i--) {
            ret += to_string(num[i]);
        }
        return ret;
    }
};
// @lc code=end

