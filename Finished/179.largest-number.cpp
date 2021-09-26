/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
bool compare1(string as, string bs) {
    int m = as.size(), n = bs.size();
    if(m == n)
        return as > bs;
    else if (m > n) {
        if(as.substr(0, n)==bs)
            return compare1(as.substr(n, m-n), bs);
        else
            return as > bs;
    }
    else {
        if (bs.substr(0, m) == as)
            return compare1(as, bs.substr(m, m-n));
        else
            return as > bs;
    }
}

bool compare(int a, int b) {
    string as = to_string(a), bs = to_string(b);
    return compare1(as, bs);
    /*
    int m = as.size(), n = bs.size();
    if(m == n)
        return as > bs;
    else if (m > n) {
        if(as.substr(0, n)==bs)
            return compare(as.substr(n, m-n), bs);
        else
            return as > bs;
    }
    else {
        if (bs.substr(0, m) == as)
            return compare(as, bs.substr(m, m-n));
        else
            return as > bs;
    }
    */
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string ret = "";
        for (auto num : nums)
            ret += to_string(num);
        return ret[0] == '0' ? "0" : ret; 
    }
};
// @lc code=end

