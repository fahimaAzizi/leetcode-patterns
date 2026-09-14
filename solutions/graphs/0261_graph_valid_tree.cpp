#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int parent,
             vector<vector<int>>& graph,
             vector<bool>& visited) {

        visited[node] = true;

        for (int neighbor : graph[node]) {

            if (neighbor == parent) {
                continue;
            }

            if (visited[neighbor]) {
                return false;
            }

            if (!dfs(neighbor, node, graph, visited)) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree with n nodes must have n - 1 edges
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);

        // Check for cycles
        if (!dfs(0, -1, graph, visited)) {
            return false;
        }

        // Check that every node is connected
        for (bool nodeVisited : visited) {
            if (!nodeVisited) {
                return false;
            }
        }

        return true;
    }
};