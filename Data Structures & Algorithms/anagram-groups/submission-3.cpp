class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::array<int, 26>, vector<string>> x;
        
        for (auto& s : strs){
            std::array<int, 26> count{};
            for (auto c : s) count[c-'a']++;
            x[count].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& [count, word] : x){
            res.push_back(std::move(word));
        }

        return res;
    }
};
