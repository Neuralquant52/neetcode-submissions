class Solution {
public:
    int helper(vector<vector<char>>& grid, int r, int c, set<pair<int, int>>& visits, int sz){
        int rows = grid.size(), columns = grid.front().size();
        if (std::min(r, c) < 0 || r == rows || c == columns ||
        visits.contains({r, c}) || grid[r][c] == '0') return 0;

        grid[r][c] = '0';
        sz++;
        visits.insert({r, c});

        sz += helper(grid, r+1, c, visits, sz);
        sz += helper(grid, r-1, c, visits, sz);
        sz += helper(grid, r, c+1, visits, sz);
        sz += helper(grid, r, c-1, visits, sz);
        return sz;
    }

    int numIslands(vector<vector<char>>& grid) {
        int count{};
        set<pair<int, int>> visits;

        for (int x{}; x < grid.size(); x++){
            for (int y{}; y < grid.front().size(); y++){
                if (helper(grid, x, y, visits, 0) > 0){
                    std::cout << x << "|" << y << '\n';
                    count++;
                    visits.clear();
                }
            }
        }
        return count;
    }
};
