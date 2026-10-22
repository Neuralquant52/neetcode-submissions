class Solution {
public:
    std::pair<int, int> valid(string s, int left, int right){
        while (left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }

        return {left+1, right - left - 1};
    }

    string longestPalindrome(string s) {
        std::pair<int, int> max = {0, 0};
        for (int i{}; i < s.size(); i++){
            max = std::max(max, valid(s, i, i), [](auto x, auto y){return x.second < y.second;});
            max = std::max(max, valid(s, i, i+1), [](auto x, auto y){return x.second < y.second;});
        }

        return s.substr(max.first, max.second);
    }
};
