class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        int currSum = 0;
        int maxSum = nums[0];

        for (int i : nums){
            currSum = max(currSum, 0);
            currSum += i;
            maxSum = std::max(maxSum, currSum);
        }
        return maxSum;
    }
};
