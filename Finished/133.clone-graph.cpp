// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem133.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int, Node*> umap;
public:
    void cloneGraph(Node* node, Node* newNode) {
        for (auto neighbor : node->neighbors) {
            //cout << neighbor->val << endl;
            if (umap.find(neighbor->val) != umap.end()) {
                newNode->neighbors.push_back(umap[neighbor->val]);
                //umap[neighbor->val]->neighbors.push_back(newNode);
                continue;
            }
                
            Node* newNeighbor = new Node(neighbor->val);
            newNode->neighbors.push_back(newNeighbor);
            //newNeighbor->neighbors.push_back(newNode);
            umap.insert({neighbor->val, newNeighbor});
            cloneGraph(neighbor, newNeighbor);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        Node* newNode = new Node(node->val);
        umap.insert({node->val, newNode});
        cloneGraph(node, newNode);
        return newNode;
    }
};
// @lc code=end

