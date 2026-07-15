class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int x{0}; x < nums.size(); x++){
            for (int y{x + 1}; y < nums.size(); y++){
                if (nums[x] == nums[y]) return nums[x];
            }
        }
        return 0;
    }
};
