class Solution {
public:
    int help(int i, vector<int>& nums, vector<optional<int>>& dp){
        if (i >= nums.size()) return 0;
        if (dp[i].has_value()) return *dp[i];

        dp[i] = std::max(help(i+1, nums, dp), nums[i]  + help(i+2, nums, dp));
        return *dp[i];
    }

    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        vector<optional<int>> dp(nums.size(), std::nullopt);
        vector<optional<int>> dp2(nums.size(), std::nullopt);

        vector<int> subvec1(nums.begin()+1, nums.end());
        vector<int> subvec2(nums.begin(), nums.begin()+nums.size()-1);
        return std::max(help(0, subvec1, dp), help(0, subvec2, dp2));
    }
};
