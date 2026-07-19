class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        for (int i{0}; i < nums.size();) {
            if (nums[i] <= 0) nums.erase(nums.begin() + i);
            else i++;
        }
        if (nums.empty()) return 1;

        for (int i{0}; i < nums.size(); i++){
            std::cout << nums[i] << std::endl;
            if (nums[i] !=  i + 1) {
                return i + 1;
            }
        }
        return nums.back() + 1;
    }
};