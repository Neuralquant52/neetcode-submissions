class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals.front());

        vector<int> curr;

        for (auto i{0uz}; i < intervals.size(); i++){
            // std::cout << std::format("Curr : {} - {} / Interval : {} - {}\n", curr[0], curr[1], intervals[i][0], intervals[i][1]);
            if (intervals[i][0] <= res.back()[1]){
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            } else res.push_back(intervals[i]);
        }

        return res;
    }
};
