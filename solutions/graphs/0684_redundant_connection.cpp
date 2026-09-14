#include <vector>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) {
            return false; // Cycle found
        }

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } 
        else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } 
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!unite(u, v)) {
                return edge;
            }
        }

        return {};
    }
};