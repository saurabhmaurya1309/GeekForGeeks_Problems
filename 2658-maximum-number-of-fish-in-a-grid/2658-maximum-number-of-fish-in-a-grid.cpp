class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m = grid.size();
    int n = grid[0].size();
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] >0) {
                queue<pair<int, int>> q;
                q.push({r, c});
                int fishCaught = 0;
                while (!q.empty()) {
                    int size = q.size();
                    while (size--) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        if (grid[row][col] > 0) {
                            fishCaught += grid[row][col];
                            grid[row][col] = 0;
                        }
                        for (auto& dir : dirs) {
                            int nr = row + dir[0];
                            int nc = col + dir[1];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                q.push({nr, nc});
                            }
                        }
                    }
                }
                maxFish = max(maxFish, fishCaught);
            }
        }
    }
    return maxFish;
        
    }
};