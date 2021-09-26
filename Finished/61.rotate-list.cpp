/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        ListNode* p = head;
        int n = 1;
        while(p->next) {
            n++;
            p = p->next;
        }
        k %= n;
        if(k == 0)
            return head;
        p->next = head;
        for (int i = 0; i < n-k; i++) {
            p = p->next;
        }
        ListNode* h = p->next;
        p->next = nullptr;
        return h;
    }
};
// @lc code=end

