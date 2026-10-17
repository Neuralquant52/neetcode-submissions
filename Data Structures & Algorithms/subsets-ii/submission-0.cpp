class Solution {
public:
    void helper(int i, vector<int> nums, vector<int>& path, set<vector<int>>& subSets){
        if (i >= nums.size()){
            subSets.insert(path);
            return;
        }

        path.push_back(nums[i]);
        helper(i + 1, nums, path, subSets);
        
        path.pop_back();
        helper(i + 1, nums, path, subSets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path; set<vector<int>> subsets;
        sort(nums.begin(), nums.end());
        helper(0, nums, path, subsets);

        vector<vector<int>> res(subsets.begin(), subsets.end());
        return res;
    }
};
