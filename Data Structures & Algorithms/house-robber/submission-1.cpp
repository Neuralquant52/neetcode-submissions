class Solution {
public:
    int dfs(int i, vector<int>& nums, vector<std::optional<int>>& memo){
        if (i >= nums.size()) return 0;
        if (memo[i].has_value()) return memo[i].value(); 
        memo[i] = std::max(dfs(i+1, nums, memo), nums[i] + dfs(i+2, nums, memo));

        return memo[i].value(); 
    }
    
    int rob(vector<int>& nums) {
        vector<std::optional<int>> memo(nums.size(), std::nullopt);

        return dfs(0, nums, memo);
    }
};
