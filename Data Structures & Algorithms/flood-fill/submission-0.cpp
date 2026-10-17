class Solution {
public:
    void helper(vector<vector<int>>& grid, int sc, int sr, int c, int r, int color, set<pair<int, int>>& visit, int original_color){
        int rows = grid.size(); int columns = grid.front().size();
        if (std::min(c, r) < 0 || c == columns || r == rows ||
        visit.contains({r, c}) || grid[r][c] != original_color) return;

        // if (c == columns-1 && r == rows-1) return;

        visit.insert({r, c});
        grid[r][c] = color;
        helper(grid, sc, sr, c+1, r, color, visit, original_color);
        helper(grid, sc, sr, c-1, r, color, visit, original_color);
        helper(grid, sc, sr, c, r+1, color, visit, original_color);
        helper(grid, sc, sr, c, r-1, color, visit, original_color);
        visit.erase({r, c});
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        set<pair<int, int>> visit;
        helper(image, sc, sr, sc, sr, color, visit, image[sr][sc]);
        return image;
    }  
};