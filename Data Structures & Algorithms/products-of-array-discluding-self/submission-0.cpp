class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec;
        int current_product = 1;
        for (int x{0}; x < nums.size(); x++){
            for (int y{0}; y < nums.size(); y++){
                if (x != y){
                    current_product *= nums[y];
                }
            }
            vec.push_back(current_product);
            current_product = 1;
        }
        return vec;
        
    }
};
