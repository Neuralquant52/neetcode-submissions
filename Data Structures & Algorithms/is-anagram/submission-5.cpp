class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        for (int x{}; x < s.size(); x++){
            for (int y{}; y < t.size(); y++){
                if (s[x] == t[y]) {
                    t.erase(y, 1);
                    break;
                };
            }
        }
        return t.empty();
    }
};
