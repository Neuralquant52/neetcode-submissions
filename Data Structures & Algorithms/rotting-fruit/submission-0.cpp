class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int fresh{};
        
        for (int x{}; x < grid.size(); x++){
            for (int y{}; y < grid.front().size(); y++){
                int curr = grid[x][y];
                if (grid[x][y] == 1) fresh++;
                else if (grid[x][y] == 2) rotten.push({x, y}); 
            }
        }
        int rows = grid.size(), columns = grid.front().size();
        vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int count{};
        if (fresh == 0) return 0;
        
        while (!rotten.empty() && fresh > 0){
            int sz = rotten.size();
            for (int i{}; i < sz; i++){
                auto [r, c] = rotten.front(); rotten.pop();

                for (auto [nr, nc] : neighbors){

                    if (std::min(r + nr, c + nc) < 0 || 
                    r + nr == rows || c + nc == columns ||
                    grid[r+nr][c+nc] == 0) continue;

                    if (grid[r+nr][c+nc] == 1) grid[r+nr][c+nc] = 2, rotten.push({r+nr, c+nc}), fresh--;
                }
            }
            count++;
        }
        return fresh == 0 ? count : -1;
    }
};
