// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    vector<string> ret;
    void backtrace(string& s, int index, string path, int num) {
        //index is current index can be chosed, path is the current possible ip, num is the remaining ip address need to be pick
        if (num == 0 && path.size() == s.size()+4)
            ret.push_back(path.substr(0, path.size()-1));
        if (index < s.size() && s[index] == '0') {
            backtrace(s, index + 1, path + s[index]+'.', num - 1);
            return;
        }
        if (index < s.size()) 
            backtrace(s, index + 1, path + s[index]+'.', num - 1);
        if (index+1 < s.size())
            backtrace(s, index + 2, path + s.substr(index, 2)+'.', num - 1);
        if (index+2 < s.size() && stoi(s.substr(index, 3)) <= 255)
            backtrace(s, index + 3, path + s.substr(index, 3)+'.',
                      num - 1);
    }

    vector<string> restoreIpAddresses(string s) {
        string path = "";
        ret = {};
        if(s.size() > 12) return ret;
        backtrace(s, 0, path, 4);
        return ret;
    }
};
// @lc code=end

