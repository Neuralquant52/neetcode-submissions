class Solution {
public:
    std::unordered_map<int, bool> dp;

    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict, 0);
    }

    bool dfs(string s, vector<string>& words, int i){
        if (i >= s.length()) return true;
        if (dp.contains(i)) return dp[i];
        
        for (auto& w : words){
            if (i + w.length() <= s.length()) dp[i] = (s.substr(i, w.length()) == w) && dfs(s, words, i+w.length());
            if (dp[i]) break;
        }
        return dp[i];
    }
};
