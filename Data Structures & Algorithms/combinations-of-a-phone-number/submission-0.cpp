class Solution {
private:
    std::map<int, vector<char>> map_ = {
        {1, {}},
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}}
    };

public:
    void helper(int idx, string digits, string& comb, vector<string>& res){
        if (idx >= digits.length()) {
            res.push_back(comb);
            return;
        }

        vector<char> x = map_[std::stoi(string(1,digits[idx]))];

        for (int i{}; i < x.size(); i++){
            comb.push_back(x[i]);
            helper(idx + 1, digits, comb, res);
            comb.pop_back();
        }
        // helper(idx +1, digits, comb, res);
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string curr;
        vector<string> res;
        
        helper(0, digits, curr, res);
        return res;
    }
};
