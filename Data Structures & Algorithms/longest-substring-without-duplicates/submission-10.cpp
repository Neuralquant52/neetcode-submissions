class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_{};
        string temp_;

        for (int i{}; i < s.size(); i++){
            while (temp_.contains(s[i])){
                temp_.erase(temp_.begin());
            }
            temp_ += s[i];
            if (temp_.size() > max_) max_ = temp_.size();
        }
        return max_;
    }
};
