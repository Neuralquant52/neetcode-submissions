class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int L{}; L < nums.size(); L++){
            int R{L+1};
            while (R <= (L+k) && R < nums.size()){
                if (nums[L] == nums[R]) return true;
                else R++;
            }
        }  
        return false;
    }
};