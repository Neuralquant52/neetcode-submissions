class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> final;
        for (int x{0}; x < nums.size(); x++){
            int count = 1;
            for (int y{0}; y < nums.size(); y++){
                if (x != y) count *= nums[y];
            }
            
            final.push_back(count);
        }
        return final;
    }
};
