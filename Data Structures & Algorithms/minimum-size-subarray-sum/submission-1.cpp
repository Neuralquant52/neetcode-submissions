class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlength{INT_MAX};

        int L{};
        int R{};
        int currSum{};
        while (R < nums.size()){
            currSum += nums[R];
            while (currSum >= target){
                minlength = std::min(R - L+1, minlength);
                currSum -= nums[L++];
            }
            R++;
        }
        return minlength == INT_MAX ? 0 : minlength;
    }
};