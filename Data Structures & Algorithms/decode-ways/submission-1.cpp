class Solution {
public:
    std::unordered_map<int, int> dp;
    int dfs(int i, const string& s){
        if (dp.contains(i)) return dp[i];

        if (i >= s.size()) return 1;
        if (s[i] == '0') return 0;

        int res = dfs(i+1, s);
        if (i < s.length()){
            if (i+1 < s.length() && (s[i] == '1' || 
            s[i] == '2' && s[i+1] < '7')) res += dfs(i+2, s);
        }
        dp[i] = res;

        return res;
    }
    int numDecodings(string s) {
        return dfs(0, s);
    }
};
