class Solution {
public:
    int helper(const vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& visit){
        int rows = grid.size(); int columns = grid.front().size();
        if (std::min(r, c) < 0 || c == columns || r == rows || 
        visit.contains({r, c})|| grid[r][c] == 1 ) return 0;

        if (c == columns-1 && r == rows-1) return 1;

        visit.insert({r, c});

        int count{0};

        count += helper(grid, r+1, c, visit);
        count += helper(grid, r-1, c, visit);
        count += helper(grid, r, c+1, visit);
        count += helper(grid,  r, c-1, visit);

        visit.erase({r, c});
        return count;
    }

    int countPaths(vector<vector<int>>& grid) {
        set<pair<int, int>> visit;
        return helper(grid, 0, 0, visit);
    }
};
