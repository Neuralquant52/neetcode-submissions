class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto calcDistance = [](std::vector<int> point){
            return std::sqrt(std::pow(point[0], 2) + std::pow(point[1], 2));
        };

        auto cmp = [&](auto x1, auto x2){
            return calcDistance(x1) > calcDistance(x2);
        };

        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp, points);

        vector<vector<int>> res;
        
        for (int i{}; i < k; i++) res.push_back(heap.top()), heap.pop();

        return res;
    }
};
