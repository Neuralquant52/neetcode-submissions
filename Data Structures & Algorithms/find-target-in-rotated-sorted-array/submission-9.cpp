class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L{};
        int R{static_cast<int>(nums.size() - 1)};
        int min{INT_MAX};
        int minIndex{};

        while (L < R){
            int mid = L + (R-L) / 2;
            if (nums[mid] < min) minIndex = mid;
            min = std::min(min, nums[mid]);
            if (nums[mid] > nums[R]) L = mid+1;
            else R = mid;
        }
        int low, high;
        if (minIndex > 0 && target > nums.back()) low = 0, high = minIndex;
        else low = minIndex, high = static_cast<int>(nums.size()-1);
        std::cout << low << " " << high << '\n';

        while (low <= high){
            if (nums[low] == target) return low;
            else if (nums[high] == target) return high;
            
            int mid = low + (high-low) / 2;
            if (target > nums[mid]) low = mid+1;
            else if (target < nums[mid]) high = mid-1;
            else return mid;
        }
        return -1;
    }
};
