/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() < 2) return true;
        std::sort(intervals.begin(), intervals.end(), [](auto x, auto y){return x.start < y.start && x.end < y.end;});
        
        Interval old = intervals[0];
        for (auto i{1uz}; i < intervals.size(); i++){
            std::cout << intervals[i].start << " " << old.end << '\n';
            if (intervals[i].start < old.end && intervals[i].end > old.start) return false;
            old = intervals[i];
        }
        return true;
    }
};
