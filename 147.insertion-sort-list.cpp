// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem147.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-5001, head);
        if (head->next == nullptr)
            return head;
        ListNode* cur = head;
        ListNode* pre = dummy;
        ListNode* nxt = nullptr;
        while(cur != nullptr) {
            nxt = cur->next;
            while(pre->next!=nullptr && pre->next->val < cur->val)
                pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = dummy;
            cur = nxt;
        }
        return dummy->next;
    }
};
// @lc code=end

