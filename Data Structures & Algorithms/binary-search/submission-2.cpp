class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target) return 0;
        else if(nums.size() == 1 && nums[0] != target) return -1;


        int high = nums.size() - 1;
        int low = 0;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) high = mid - 1;
            else if (nums[mid] < target) low = mid + 1;
            else return mid;
        }
        return -1;
    }
};
