class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& visits){
        int rows = grid.size(), columns = grid.front().size();
        if (std::min(r, c) < 0 || 
        r == rows || c == columns || 
        visits.contains({r, c}) || grid[r][c] == 0) return 0;

        visits.insert({r, c});

        return 1 + dfs(grid, r+1, c, visits) + dfs(grid, r-1, c, visits) + dfs(grid, r, c+1, visits) + dfs(grid, r, c-1, visits);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        set<pair<int, int>> visits;
        int max{};
        for (int x{}; x < grid.size(); x++){
            for (int y{}; y < grid.front().size(); y++){
                max = std::max(max, dfs(grid, x, y, visits));
            }
        }
        return max;
    }
};
