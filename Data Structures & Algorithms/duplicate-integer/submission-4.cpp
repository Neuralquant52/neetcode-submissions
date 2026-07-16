#include <vector>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) { 
        for (auto x{0}; x < nums.size(); x++){
            for (auto y{x + 1}; y < nums.size(); y++){
                if (nums[x] == nums[y])  return true;
            }
        }
        return false;
    }
};