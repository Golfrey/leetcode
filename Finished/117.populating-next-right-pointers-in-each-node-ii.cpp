/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            Node* p;
            for (int i = 0; i < n - 1; i++) {
                p = q.front();
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                p->next = q.front();
            }
            p = q.front();
            q.pop();
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            p->next = nullptr;
        }
        return root;
    }
};
// @lc code=end

