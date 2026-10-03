class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (int x{}; x < nums.size(); x++){
            for (int y{x + 1}; y < nums.size(); y++){
                if (nums[x] == nums[y]) return true;
            }
        }
        return false;
    }
};