#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Out of bounds or water
        if (row < 0 || row >= rows ||
            col < 0 || col >= cols ||
            grid[row][col] == '0') {
            return;
        }

        // Mark as visited
        grid[row][col] = '0';

        // Explore four directions
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {

                if (grid[row][col] == '1') {
                    count++;

                    dfs(grid, row, col);
                }
            }
        }

        return count;
    }
};