#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        const int INF = 1e9;

        vector<int> dist(n, INF);
        dist[src] = 0;

        // At most k stops means at most k + 1 flights
        for (int i = 0; i <= k; i++) {

            vector<int> nextDist = dist;

            for (auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if (dist[from] == INF) {
                    continue;
                }

                nextDist[to] = min(
                    nextDist[to],
                    dist[from] + price
                );
            }

            dist = nextDist;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};