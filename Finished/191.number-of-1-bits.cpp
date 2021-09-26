/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret=0;
        for (int i = 0; i < 32; i++) {
            if (n >> i & 1)
                ret++;
        }
        return ret;
    }
};
// @lc code=end

