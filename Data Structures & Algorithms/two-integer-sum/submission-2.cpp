class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        for (auto x{0}; x < nums.size(); x++){
            for (auto y{x + 1}; y < nums.size(); y++){
                if ((nums[x] + nums[y]) == target){
                    if (result.size() >= 2){
                        break;
                    }
                    result.push_back(x);
                    result.push_back(y);
                }
            }
        }
        return result;
    }
};