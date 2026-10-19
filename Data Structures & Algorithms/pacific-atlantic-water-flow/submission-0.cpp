class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& visits, int prevHeight){
        int rows = grid.size(), columns = grid.front().size();
        if (std::min(r, c) < 0 || 
        r == rows || c == columns ||
        visits.contains({r, c}) || grid[r][c] < prevHeight) return;

        visits.insert({r, c});
        dfs(grid, r+1, c, visits, grid[r][c]);
        dfs(grid, r-1, c, visits, grid[r][c]);
        dfs(grid, r, c+1, visits, grid[r][c]);
        dfs(grid, r, c-1, visits, grid[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int rows = heights.size(), columns = heights.front().size();
        set<pair<int, int>> atl, pac;

        for (int i{}; i < columns; i++){
            dfs(heights, 0, i, pac, heights[0][i]);
            dfs(heights, rows-1, i, atl, heights[rows-1][i]);
        }        

        for (int i{}; i < rows; i++){
            dfs(heights, i, 0, pac, heights[i][0]);
            dfs(heights, i, columns-1, atl, heights[i][columns-1]);
        }

        for (int x{}; x < heights.size(); x++){
            for (int y{}; y < heights.front().size(); y++){
                if (atl.contains({x, y}) && pac.contains({x, y})) res.push_back({x, y});
            }
        }

        return res;
    }   
};
