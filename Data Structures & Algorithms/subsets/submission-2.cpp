class Solution {
public:
    void helper(int i, vector<int> nums, vector<int>& currSet, vector<vector<int>>& subsets){
        if (i >= nums.size()){
            subsets.push_back(currSet);
            return;
        }

        currSet.push_back(nums[i]);
        helper(i + 1, nums, currSet, subsets);

        currSet.pop_back();
        helper(i+1, nums, currSet, subsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSet; vector<vector<int>> subsets;
        helper(0, nums, currSet, subsets);
        return subsets;
    }
};
