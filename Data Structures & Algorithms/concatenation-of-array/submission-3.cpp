class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> vec(nums.begin(), nums.end());
        for (size_t i{}; i < nums.size(); i++){
            vec.push_back(nums[i]);
        }
        return vec;
    }
};