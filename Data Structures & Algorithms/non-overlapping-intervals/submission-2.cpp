class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return 0;
        std::sort(intervals.begin(), intervals.end());

        int count{};
        int prevEnd = intervals[0][1];
        for (int i{1}; i < intervals.size(); i++){
            if (intervals[i][0] >= prevEnd){
                prevEnd = intervals[i][1];
            } else {
                prevEnd = std::min(intervals[i][1], prevEnd);
                count++;
            }
        }
        return count;
        
    }
};
