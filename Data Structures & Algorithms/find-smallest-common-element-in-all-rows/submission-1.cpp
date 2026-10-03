class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        for (size_t x{}; x < mat.size(); x++){
            for (size_t y{}; y < mat.front().size(); y++){
                data_[mat[x][y]]++;
            }
        }
        
        std::vector<std::pair<int, unsigned int>> vec(data_.begin(), data_.end());
        std::sort(vec.begin(), vec.end(), [](const auto& x, const auto& y){
            return x.second > y.second;
        });


        if (vec.empty() || vec.front().second != mat.size()) return -1;

        std::erase_if(vec, [vec](const auto& p){
            return p.second != vec.front().second;
        });

        std::sort(vec.begin(), vec.end(), [](const auto& x, const auto& y){
            return x.first < y.first;
        });

        if (vec.empty()) return -1;
        else return vec.front().first;
    };

private:
    std::unordered_map<int, unsigned int> data_;
};
