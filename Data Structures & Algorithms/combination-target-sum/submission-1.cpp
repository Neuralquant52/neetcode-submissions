class Solution {
public:
    void helper(int i, vector<int> nums, vector<int>& comb, vector<vector<int>>& res, int target){
        if (target == 0){
            res.push_back(comb);
            return;
        }

        if (target < 0 || i >= nums.size()) return;

        comb.push_back(nums[i]);
        helper(i, nums, comb, res, target-nums[i]);

        comb.pop_back();
        helper(i+1, nums, comb, res, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> res;

        helper(0, nums, curr, res, target);
        return res;
    }
};
