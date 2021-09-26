/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head, int len) {
        if(len <= 0)
            return nullptr;
        int middle = len / 2;
        ListNode* p = head;
        for (int i = 0; i < middle; i++)
            p = p->next;
        TreeNode* root = new TreeNode(p->val);
        root->left = sortedListToBST(head, middle - 1);
        root->right = sortedListToBST(p->next, len - middle);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        int n = 0;
        ListNode* p = head;
        while(p) {
            p = p->next;
            n++;
        }
        int middle = n / 2;
        p = head;
        for (int i = 0; i < middle; i++)
            p = p->next;
        TreeNode* root = new TreeNode(p->val);
        root->left = sortedListToBST(head, middle - 1);
        root->right = sortedListToBST(p->next, n - middle);
        return root;
    }
};
// @lc code=end

