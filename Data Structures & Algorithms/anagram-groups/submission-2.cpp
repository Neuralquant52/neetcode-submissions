class Solution {
public:
    bool anagram(string a, string b){
        if (a.size() != b.size()) return false;
        int count = 0;
        for (int x{0}; x < a.size(); x++){
            for (int y{0}; y < b.size(); y++){
                if (a[x] == b[y]){
                    b.erase(y, 1);
                    count++;
                    break;
                }
            }
        }
        return (count == a.size());
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string base;
        vector<vector<string>> final_vec;
        vector<string> vec;
        for (int x{0}; x < strs.size(); x++){
            base = strs[x];
            vec.push_back(base);
            strs.erase(strs.begin() + x);
            x--;
            for (int y{0}; y < strs.size(); y++){
                if (base != strs[y]){
                    if (anagram(base, strs[y])) {
                        vec.push_back(strs[y]);
                        strs.erase(strs.begin() + y);
                        y--;
                    }
                } else {
                    vec.push_back(strs[y]);
                    strs.erase(strs.begin() + y);
                    y--;
                }
            } 
            final_vec.push_back(vec);
            vec.clear();
        }
        return final_vec;
    }
};
