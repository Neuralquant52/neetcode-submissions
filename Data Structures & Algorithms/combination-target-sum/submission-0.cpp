class Solution {
public:
    void dfs(int i, vector<int> actual, vector<int> nums, vector<vector<int>>& final, int sum, int target){        
        if (i >= nums.size() || sum > target) return;
        if (sum == target){
            final.push_back(actual);
            return;
        }
        actual.push_back(nums[i]);

        dfs(i, actual, nums, final, sum + nums[i], target);
        actual.pop_back();
        dfs(i + 1, actual, nums, final, sum, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> final;
        vector<int> actual;

        dfs(0, actual, nums, final, 0, target);
        return final;
    }
};
