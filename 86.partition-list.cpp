/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr)
            return head;
        ListNode *vHead = new ListNode(0, head), *p = vHead, *cur = vHead;
        while(p->next) {
            if(p->next->val < x) {
                ListNode* tmp = p->next;
                p->next = cur->next;
                cur->next = p->e
            }
        }
    }
};
// @lc code=end

