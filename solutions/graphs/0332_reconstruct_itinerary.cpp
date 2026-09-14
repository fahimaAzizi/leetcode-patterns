#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<
        string,
        vector<string>,
        greater<string>
    >> graph;

    vector<string> itinerary;

    void dfs(string airport) {
        while (!graph[airport].empty()) {
            string nextAirport = graph[airport].top();
            graph[airport].pop();

            dfs(nextAirport);
        }

        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};