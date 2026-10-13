class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min{INT_MAX};
        int L{};
        int R{};
        int currSum{};

        while (R < nums.size()){
            currSum += nums[R];
            std::cout << currSum << '\n';

            if (currSum >= target){
                while (L < nums.size() && currSum >= target) {
                    currSum -= nums[L];
                    min = std::min(min, R-L+1);
                    L++;
                }     
            }
            R++;
        }     
        return min == INT_MAX ? 0 : min;
    }
};