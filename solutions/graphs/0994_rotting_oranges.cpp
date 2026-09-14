#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Add all rotten oranges to the queue
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty() && fresh > 0) {
            int size = q.size();

            // One BFS level = one minute
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= rows ||
                        nc < 0 || nc >= cols) {
                        continue;
                    }

                    if (grid[nr][nc] != 1) {
                        continue;
                    }

                    // Make fresh orange rotten
                    grid[nr][nc] = 2;
                    fresh--;

                    q.push({nr, nc});
                }
            }

            minutes++;
        }

        // If fresh oranges remain, they cannot be reached
        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};