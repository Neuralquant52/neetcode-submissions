class Solution {
public:
    void dfs(int i, vector<int>& actual, vector<int>& nums, vector<vector<int>>& final){  
        if (i >= nums.size()) return;
        actual.push_back(nums[i]);
        final.push_back(actual);

        dfs(i + 1 , actual, nums, final);
        actual.pop_back();
        dfs(i + 1 , actual, nums, final);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> final = {{}};
        vector<int> actual;
        dfs(0, actual, nums, final);
        return final;
    }
};
