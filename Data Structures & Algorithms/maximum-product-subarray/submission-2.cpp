class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0], mx = nums[0], mn = nums[0];

        for (int i{1}; i < nums.size(); i++){
            std::vector<int> candidates = {nums[i], mx*nums[i], mn*nums[i]};

            mn = *std::min_element(candidates.begin(), candidates.end());
            mx = *std::max_element(candidates.begin(), candidates.end());

            max = std::max(max, mx);
        }

        return max;
    }
};
