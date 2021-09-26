/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> umap;

public:
    Node* copyList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* newNode = new Node(head->val);
        umap[head] = newNode;
        newNode->next = copyList(head->next);
        return newNode;
    }

    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        Node* newHead = copyList(head);
        Node* p = head;
        while(p) {
            umap[p]->random = umap[p->random];
            p = p->next;
        }
        return newHead;
    }
};
// @lc code=end

