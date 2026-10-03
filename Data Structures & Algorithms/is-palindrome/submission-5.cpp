class Solution {
public:
    bool isPalindrome(string s) {
        size_t l = 0;
        size_t r = s.size() - 1;

        bool res = true;
        
        while (l < r){
            if (!res) return res;
            if (!std::isalnum(s[l])){
                l++; 
                continue;
            };
            if (!std::isalnum(s[r])){
                r--;
                continue;
            }

            res = res && (std::tolower(s[l]) == std::tolower(s[r]));
            l++;
            r--;
        }
        return res;
    }
};
