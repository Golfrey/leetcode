/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long int ans=0;
        while(x != 0){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if ( ans < INT_MIN ||  ans > INT_MAX) return 0;
        return ans;
    }
};
// @lc code=end

