#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> cloned;

    Node* dfs(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        // Already cloned
        if (cloned.count(node)) {
            return cloned[node];
        }

        // Create clone
        Node* copy = new Node(node->val);

        // Store before exploring neighbors
        cloned[node] = copy;

        // Clone neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor));
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};