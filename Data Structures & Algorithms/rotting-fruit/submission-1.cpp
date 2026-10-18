class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh{};
        int count{};
        queue<pair<int, int>> rotten;

        for (int x{}; x < grid.size(); x++){
            for (int y{}; y < grid.front().size(); y++){
                if (grid[x][y] == 1) fresh++;
                else if (grid[x][y] == 2) rotten.push({x, y});
            }
        }

        vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int rows = grid.size(), columns = grid.front().size();

        while (!rotten.empty() && fresh > 0){
            int sz = rotten.size();
            for (int i{}; i < sz; i++){
                auto [r, c] = rotten.front(); rotten.pop();
                for (auto [nr, nc] : neighbors){
                    if (std::min(r + nr, c + nc) < 0 ||
                    r+nr == rows ||  c+nc == columns || 
                    grid[r + nr][c + nc] == 0) continue;

                    if (grid[r+nr][c+nc] == 1) grid[r+nr][c+nc] = 2, rotten.push({r+nr, c+nc}), fresh--;
                }
            }
            count++;
        }

        return fresh == 0 ? count : -1;
    }
};
