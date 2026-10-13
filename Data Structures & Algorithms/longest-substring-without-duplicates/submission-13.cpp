class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int max{};

        int L{};
        int R{L + 1};
        while (R < s.size()){

            auto it = std::find(s.begin() + L, s.begin() + R, s[R]);
            if (it == s.begin() + R) R++;
            else {
                max = std::max(R-L, max);
                L++;
            }
        }
        max = std::max(R-L, max);
        return max;
    }
};
