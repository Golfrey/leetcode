/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        unsigned long long m = 0;
        q.push(pair<TreeNode*, unsigned long long>(root, 1));
        while (!q.empty()) {
            unsigned long long l = q.front().second, r = l;
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) q.push(pair<TreeNode*, unsigned long long>(node->left, r * 2));
                if (node->right) q.push(pair<TreeNode*, unsigned long long>(node->right, r * 2 + 1));
            }
            m = max(m, r + 1 - l);
        }
        return m;
    }
};
// @lc code=end
