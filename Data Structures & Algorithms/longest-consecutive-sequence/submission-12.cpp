class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::sort(nums.begin(), nums.end());
        int count_{1};
        vector<int> vec;

        for (size_t i{}; i < (nums.size() - 1); i++){
            if (nums[i] == nums[i + 1]) continue;
            else if (nums[i + 1] - nums[i] == 1) count_++;
            else {
                vec.push_back(count_);
                count_ = 1;
            }
        }
        vec.push_back(count_);
        return *std::max_element(vec.begin(), vec.end());
    }
};
