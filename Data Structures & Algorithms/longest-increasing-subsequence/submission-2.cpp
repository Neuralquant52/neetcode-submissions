class Solution {
public:
    int dfs(vector<int>& nums, int i, int j, vector<vector<optional<int>>>& dp){
        if (i >= nums.size()) return 0;
        if (dp[i][j+1].has_value()) return *dp[i][j+1];

        int LIS = dfs(nums, i+1, j, dp);

        if (j == -1 || nums[i] > nums[j]) LIS = std::max(LIS, 1 + dfs(nums, i+1, i, dp));

        dp[i][j+1] = LIS;
        return *dp[i][j+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<optional<int>>> dp(nums.size(), vector<optional<int>>(nums.size() + 1, std::nullopt));
        return dfs(nums, 0, -1, dp);
    }
};
