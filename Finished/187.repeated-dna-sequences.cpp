/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_set<string> us;
        unordered_set<string> ret;
        for (int i = 0; i <= n - 10; i++) {
            string dna = s.substr(i, 10);
            if(us.find(dna) == us.end()) {
                us.insert(dna);
            }
            else
                ret.insert(dna);
        }
        return vector<string>(ret.begin(), ret.end());
    }
};
// @lc code=end

