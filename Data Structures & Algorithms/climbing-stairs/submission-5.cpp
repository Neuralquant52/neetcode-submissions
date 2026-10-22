class Solution {
public:
    int help(int i, int n, vector<std::optional<int>>& memo){
        if (i >= n) return i == n ? 1 : 0;
        if (memo[i].has_value()) return memo[i].value();

        memo[i] = help(i+1, n, memo) + help(i+2, n, memo);
        return memo[i].value();
    }

    int climbStairs(int n) {
        vector<std::optional<int>> memo(n, std::nullopt);
        return help(0, n, memo);
    }
};
