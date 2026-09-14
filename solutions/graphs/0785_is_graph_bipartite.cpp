#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // -1 = not colored
        //  0 = first group
        //  1 = second group
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {

            // Handle disconnected components
            if (color[start] != -1) {
                continue;
            }

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {

                    // Give neighbor opposite color
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }

                    // Same color means not bipartite
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};