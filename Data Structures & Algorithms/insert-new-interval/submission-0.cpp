class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i{};
        int n{static_cast<int>(intervals.size())};

        while (i < n && newInterval[0] > intervals[i][1]){
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = std::min(intervals[i][0], newInterval[0]);
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < n){
            res.push_back(intervals[i]);
            i++;
        }


        return res;
    }
};
