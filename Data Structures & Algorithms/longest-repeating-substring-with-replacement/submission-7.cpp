class Solution {
public:
    int characterReplacement(string s, int k) {
        std::array<int, 26> count = {};
        int L=0, res=0;
        for (int R{}; R < (int)s.size(); R++){
            count[static_cast<int>(s[R] - 'A')]++;
            int mostFreq = *std::max_element(count.begin(), count.end());
            if ((R - L+1)  - mostFreq > k){ 
                count[static_cast<int>(s[L] - 'A')]--;
                L++;
            }
            res = std::max(res, R - L + 1);
        }
        return res;
    }
};
