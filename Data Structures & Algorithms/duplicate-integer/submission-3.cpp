#include <vector>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) { 
        int match_count = 0;
        for (auto x{0}; x < nums.size(); x++){
            for (auto y{0}; y < nums.size(); y++){
                if (nums[x] == nums[y]){
                    match_count++;
                    if (match_count >= 2){
                        return true;
                    }
                }
            }
            match_count = 0;

        }
        return false;
    }
};