/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* p = head;
        vector<ListNode*> ret;
        int n = 0;
        while(p != nullptr) {
            p = p->next;
            n++;
        }
        int small = n / k;
        int bigNum = n - small * k, big = small + 1;
        p = head;
        for (int i = 0; i < bigNum; i++) {
            ret.push_back(p);
            for (int i = 0; i < big - 1; i++) {
                p = p->next;
            }
            ListNode* tmp = p;
            p = p->next;
            tmp->next = nullptr;
        }
        for (int i = 0; i < k - bigNum; i++) {
            ret.push_back(p);
            for (int i = 0; i < small - 1; i++) {
                p = p != nullptr ? p->next : nullptr;
            }
            if(p!=nullptr) {
                ListNode* tmp = p;
                p = p->next;
                tmp->next = nullptr;
            }
        }
        return ret;
    }
};
// @lc code=end
