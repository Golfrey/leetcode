/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void backtrace(TreeNode* p, string path, int& sum) {
        if(!p->left && !p->right) {
            sum += stoi(path + to_string(p->val));
            return;
        }
        if (p->left)
            backtrace(p->left, path + to_string(p->val), sum);
        if (p->right)
            backtrace(p->right, path + to_string(p->val), sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string path = "";
        backtrace(root, path, sum);
        return sum;
    }
};
// @lc code=end

