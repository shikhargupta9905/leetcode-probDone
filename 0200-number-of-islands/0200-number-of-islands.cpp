#include <vector>

class Solution {
private:
    void dfs(std::vector<std::vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case: check boundary conditions and water cells ('0')
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
            return;
        }
        
        // Mark the current cell as visited by setting it to '0'
        grid[r][c] = '0';
        
        // Visit all 4 adjacent directions (up, down, left, right)
        dfs(grid, r - 1, c); // Up
        dfs(grid, r + 1, c); // Down
        dfs(grid, r, c - 1); // Left
        dfs(grid, r, c + 1); // Right
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c); // Sink the connected island
                }
            }
        }
        
        return count;
    }
};