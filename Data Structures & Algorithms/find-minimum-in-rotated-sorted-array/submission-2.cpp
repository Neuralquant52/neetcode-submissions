class Solution {
public:
    int findMin(vector<int> &nums) {
        int min{INT_MAX};
        int L{};
        int R{static_cast<int>(nums.size()-1)};

        while (L <= R){
            int mid = L + (R-L) / 2;
            min = std::min(min, nums[mid]);
            if (nums[mid] < nums[R]) R = mid-1;
            else L = mid+1;
        }
        return min;
    }
};
