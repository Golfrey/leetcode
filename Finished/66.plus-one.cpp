/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        int plus = 1;
        for (int i = n; i >= 0; i--) {
            digits[i] = (digits[i] + plus) % 10;
            if(digits[i] != 0) {
                plus = 0;
                break;
            }
            else
                plus = 1;
        }
        if(plus == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end

