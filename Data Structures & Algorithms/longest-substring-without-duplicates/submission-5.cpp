class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        bool valid = true;
        for (int left{0}; left < s.size(); left++){
            if (max < 1) max = 1;
            valid = true;
            for (int right{left + 1}; right < s.size(); right++){
                
                for (int i{left}; i < right; i++){
                    if (s[i] == s[right]) valid = false;
                }
                if (valid && (right - left + 1) > max) max = right - left + 1;
            }
        }
        return max;
    }
};
