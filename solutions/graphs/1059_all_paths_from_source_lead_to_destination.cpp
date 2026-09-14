#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, int destination,
             vector<vector<int>>& graph,
             vector<int>& state) {

        // Destination must be a terminal node
        if (graph[node].empty()) {
            return node == destination;
        }

        // Cycle detected
        if (state[node] == 1) {
            return false;
        }

        // Already checked
        if (state[node] == 2) {
            return true;
        }

        // Mark as currently visiting
        state[node] = 1;

        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, destination, graph, state)) {
                return false;
            }
        }

        // Mark as completely processed
        state[node] = 2;

        return true;
    }

    bool leadsToDestination(int n,
                            vector<vector<int>>& edges,
                            int source,
                            int destination) {

        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<int> state(n, 0);

        return dfs(source, destination, graph, state);
    }
};