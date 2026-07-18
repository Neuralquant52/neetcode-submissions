class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i{1}; i < nums.size(); i++){
            while (i > 0 && nums[i] < nums[i-1]){
                int key = nums[i-1];
                nums[i - 1] = nums[i];
                nums[i] = key;
                i--;
            }
        }
    }
};