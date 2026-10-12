#include <vector>

class Solution {
private:
    vector<pair<int , int >> dir{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(std::vector<std::vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case: check boundary conditions and water cells ('0')
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') {
            return;
        }
        
        // Mark the current cell as visited by setting it to '0'
        grid[r][c] = '$';

        
        // Visit all 4 adjacent directions (up, down, left, right)
        for(pair<int , int > &p: dir){
            int k = r+p.first;
            int l = c+p.second;
            dfs(grid, k,l);
        }
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