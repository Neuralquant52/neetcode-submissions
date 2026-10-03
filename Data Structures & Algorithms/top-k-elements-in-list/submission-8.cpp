class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> x;

        for (auto& i : nums){
            x[i]++;
        }

        vector<std::pair<int, int>> data_(x.begin(), x.end());
        std::sort(data_.begin(), data_.end(), [](const auto& x, const auto& y){return x.second > y.second;});

        size_t count_{};
        vector<int> vec;
        for (auto [x, y] : data_){
            if (count_ >= k) break;
            vec.push_back(x);
            count_++;
        }
        return vec;
    }
};
