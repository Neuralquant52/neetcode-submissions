class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::sort(nums.begin(), nums.end());
        vector<int> vec;

        int count = 1;
        for (int i{0}; i < nums.size() - 1; i++){
            if (nums[i] == nums[i + 1]) continue;
            if (nums[i + 1] - nums[i] == 1) count++;
            else {
                vec.push_back(count);
                count = 1;
            }
        }
        vec.push_back(count);
        
        if (vec.size() <= 1) return vec[0];
        int max = vec[0];
        for (int i : vec){
            if (i > max) max = i;
        };
        return max;
    }
};
