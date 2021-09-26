/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool backtrace(string& s, int index, unordered_set<string>& us, const int& minLen, const int& maxLen) {
        if(index == s.size())
            return true;
        bool flag = false;

        for (int i = minLen; i <= maxLen && (index + i) <= s.size(); i++) {
            //cout << s.substr(index, i) << endl;
            if (us.find(s.substr(index, i)) != us.end())
                flag |= backtrace(s, index + i, us, minLen, maxLen);
        }
        return flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<char> us1;
        for (auto c : s)
            us1.insert(c);
        for(auto word : wordDict)
        for(auto c : word)
            us1.erase(c);
        if(!us1.empty())
            return false;
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        int maxLen = 0, minLen = 21;
        for (auto st : wordDict) {
            int n = st.size();
            maxLen = max(maxLen, n);
            minLen = min(minLen, n);
        }
        return backtrace(s, 0, us, minLen, maxLen);
    }
};
// @lc code=end

