class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;

        int rows = grid.size(), columns = grid.front().size();
        deque<pair<int, int>> queue_; 
        set<pair<int, int>> visit;
        queue_.push_back({0, 0});
        visit.insert({0, 0});

        int length{1};
        while (!queue_.empty()){
            int sz = queue_.size();
            for (int i{}; i < sz; i++){
                auto [r, c] = queue_.front(); 
                queue_.pop_front();

                if (r == rows-1 && c == columns-1) return length;

                vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
                for (auto [nr, nc] : neighbors){
                    if (std::min(r+nr, c+nc) < 0 ||
                    r + nr == rows || c + nc == columns ||
                    visit.contains({r+nr, c+nc}) || grid[r+nr][c+nc] == 1) continue;

                    queue_.push_back({r+nr, c+nc});
                    visit.insert({r+nr, c+nc});
                }
            }
            length++;
        }
        return -1;
    }
};