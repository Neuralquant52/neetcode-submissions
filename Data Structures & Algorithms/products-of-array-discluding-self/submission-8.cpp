class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) { 
        int N = nums.size(); 
        vector<int> left(N);
        vector<int> right(N);
        left[0] = nums[0];
        right.back() = nums.back();

        vector<int> res(N);
        
        for (int i{1}; i < N; i++) left[i] = left[i-1] * nums[i];
        for (int i{N-2}; i >= 0; i--) right[i] = right[i+1] * nums[i];

        for (int i{}; i < N; i++){
            int l = (i > 0) ? left[i-1] : 1;
            int r = (i < N-1) ? right[i+1] : 1;
            res[i] = l * r;
        }
        return res;
    }
};
