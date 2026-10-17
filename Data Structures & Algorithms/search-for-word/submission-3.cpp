class Solution {
public:
    bool helper(vector<vector<char>>& grid, int c, int r, string word, std::set<pair<int, int>>& visit, int idx){
        if (idx == word.length()) return true;

        int rows = grid.size(); int columns = grid.front().size(); 
        if (std::min(c, r) < 0 || c == columns || r == rows ||
        visit.contains({c, r})) return false;

        
        if (grid[r][c] == word[idx]) idx++;
        else return false;

        visit.insert({c, r});
        if (helper(grid, c+1, r, word, visit, idx) ||
        helper(grid, c-1, r, word,  visit, idx) ||
        helper(grid, c, r+1, word, visit, idx) ||
        helper(grid, c, r-1, word, visit, idx)) return true;
        visit.erase({c, r});


        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int, int>> visits;

        for (int x{}; x < board.size(); x++){
            for (int y{}; y < board.front().size(); y++){
                if (helper(board, y, x, word, visits, 0)) return true;
                visits.clear();
            }
        }
        return false;
    }
};
