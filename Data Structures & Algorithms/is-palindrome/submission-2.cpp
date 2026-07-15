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
        int x = 0;
        int y = s.size() - 1;
        bool palindrome = true;

        while(x <= (s.size() / 2)){
            char start = (char)std::tolower(s[x]);
            char end = (char)std::tolower(s[y]);
            palindrome = palindrome && (start == end);
            if (palindrome == false) break;
            x++;
            y--;
        }
        return palindrome;
    }
};
