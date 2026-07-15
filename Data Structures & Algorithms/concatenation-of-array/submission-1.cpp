class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> vec = nums;
        for (auto i{0}; i < nums.size(); i++){
            vec.push_back(nums[i]);
        }
        return vec;
    };
};