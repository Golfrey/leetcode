/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        unordered_map<char, int> umap{{'I', 1},   {'V', 5},   {'X', 10},
                                 {'L', 50},  {'C', 100}, {'D', 500},
                                 {'M', 1000}};
        for (int i = 0; i < s.size(); i++) {
            ret += umap[s[i]];
            if(i >= 1) {
                if(s[i-1]=='I' && (s[i]=='V' || s[i] =='X'))
                    ret -= 2;
                else if(s[i-1]=='X' && (s[i]=='L' || s[i] =='C'))
                    ret -= 20;
                else if(s[i-1]=='C' && (s[i]=='D' || s[i] =='M'))
                    ret -= 200;
            }
        }
        return ret;
    }
};
// @lc code=end

