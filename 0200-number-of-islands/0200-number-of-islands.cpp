#include <vector>
#include <queue>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int island_count = 0;

        // Direction vectors for moving Up, Down, Left, Right
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Found a new island
                if (grid[r][c] == '1') {
                    island_count++;
                    grid[r][c] = '0'; // Mark as visited right away

                    std::queue<std::pair<int, int>> q;
                    q.push({r, c});

                    // BFS traversal for the current island
                    while (!q.empty()) {
                        auto [curr_r, curr_c] = q.front();
                        q.pop();

                        // Check all 4 adjacent neighbors
                        for (auto& dir : directions) {
                            int next_r = curr_r + dir.first;
                            int next_c = curr_c + dir.second;

                            // Check boundaries and whether it's unvisited land
                            if (next_r >= 0 && next_r < rows && next_c >= 0 && next_c < cols && grid[next_r][next_c] == '1') {
                                grid[next_r][next_c] = '0'; // Mark as visited
                                q.push({next_r, next_c});  // Add to queue for next level traversal
                            }
                        }
                    }
                }
            }
        }

        return island_count;
    }
};