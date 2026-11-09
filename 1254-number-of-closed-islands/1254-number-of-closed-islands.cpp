#include <vector>

class Solution {
private:
    int rows, cols;

    void dfs(int r, int c, std::vector<std::vector<int>>& grid) {
        // Out of bounds or water cell
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark current land as visited by turning it into water (1)
        grid[r][c] = 1;
        
        // Explore all 4 directions
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        // Step 1: Flood-fill all 0s connected to the borders (turn them into 1s)
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(r, c, grid);
                }
            }
        }
        
        // Step 2: Count remaining isolated 0s (closed islands)
        int closedIslandsCount = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    closedIslandsCount++;
                    dfs(r, c, grid); // Sink the entire closed island
                }
            }
        }
        
        return closedIslandsCount;
    }
};