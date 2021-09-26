/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution {
public:
 int longestSubstring(string s, int k) { 
        if(s.size() == 0)
            return 0;
        unordered_map<char, int> umap;
        int ret;
        for (auto c : s) 
            umap[c]++;
        for (int i = 0; i < s.size(); i++) {
            if(umap[s[i]] < k) {
                if(i > 0 && i < s.size()-1)
                    return max(longestSubstring(s.substr(0, i), k), longestSubstring(string(s.begin()+i+1, s.end()), k));
                else if(i == 0) return longestSubstring(string(s.begin()+1, s.end()), k);
                else if(i == s.size()-1)
                    return s.size() - 1;
            }
        }
        return s.size();
 }
 };
 // @lc code=end
