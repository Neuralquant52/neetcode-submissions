class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        std::sort(nums.begin(), nums.end());

        for (int l{}; l < nums.size(); l++){
            if (l > 0 && nums[l - 1] == nums[l]) continue;
            int m = l+1;
            int r = nums.size() - 1;

            while (m < r){
                int sum{nums[l] + nums[m] + nums[r]};
                if (sum > 0) r--;
                else if (sum < 0) m++;
                else {
                    vec.push_back({nums[l], nums[m], nums[r]});

                    while (m < r && nums[m] == nums[m+1]) m++;
                    while (m < r && nums[r] == nums[r-1]) r--;
                    m++;
                    r--;
                }
            }
        }
        return vec;
    }
};
