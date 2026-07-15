#include <cctype>

class Solution {
public:
    void removeSpecialCharacter(string& s)
    {
        for (int i = 0; i < s.size(); i++) {
            bool isLetter = (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z');
            bool isDigit = (s[i] >= '0' && s[i] <= '9');

            if (!isLetter && !isDigit) {
                s.erase(i, 1);
                i--;
            }
        }
    }

    bool isPalindrome(string s) {
        removeSpecialCharacter(s);
        char start = (char)std::tolower(s.front());
        char end = (char)std::tolower(s.back());
        if (s.size() == 0 || s.size() == 1) return true;
        return (start == end) && isPalindrome(s.substr(1, s.size() - 2));
    }
};
