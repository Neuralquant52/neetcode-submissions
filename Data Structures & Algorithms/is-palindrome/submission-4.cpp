class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.size() - 1;
        int left = 0;
        
        while (left < right){
            if (!isalnum(s[right])){ 
                right--;
                continue;
            }
            if (!isalnum(s[left])){
                left++;
                continue;
            }
            else {
                std::cout << s[right] << " | " << s[left] << std::endl;
                if (tolower(s[right]) != tolower(s[left])) return false;
                left++;
                right--;
            }
        }
        return true;
    }
};
