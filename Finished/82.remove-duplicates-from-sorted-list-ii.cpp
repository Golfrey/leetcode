/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *vHead = new ListNode(-101, head), *p = head, *pre = vHead;
        while (p && p->next) {
            if(p->next->val != p->val) {
                pre = p;
                p = p->next;
                continue;
            }
            while (p->next && p->next->val == p->val)
                p = p->next;
            pre->next = p->next;
            p = p->next;
        }
        return vHead->next;
    }
};
// @lc code=end

