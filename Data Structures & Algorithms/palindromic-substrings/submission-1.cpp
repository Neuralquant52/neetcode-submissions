class Solution {
public:
    int maxPalindrome(int l, int r, string s){
        int count{};
        while (l >= 0 && r < s.length() && s[r] == s[l]){
            l--;
            r++;
            count++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int sum{};
        for (int i{}; i < s.size(); i++){
            sum += maxPalindrome(i, i, s) + maxPalindrome(i, i+1, s);
        }
        return sum;
    }
};
