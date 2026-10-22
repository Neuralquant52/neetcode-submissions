class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int max_reach{};

        for (int i{}; i < nums.size(); i++){

            if (i > max_reach) return false;
            max_reach = std::max(max_reach, i + nums[i]);
        }
        return true;
    }
};
