/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        int tmp = x;
        if (x < 0)
            return false;
        unsigned long long palindrome = 0;
        while(x) {
            palindrome = palindrome * 10 + x % 10;
            x /= 10;
        }
        //cout << palindrome << endl;
        return tmp == palindrome;
    }
};
// @lc code=end

