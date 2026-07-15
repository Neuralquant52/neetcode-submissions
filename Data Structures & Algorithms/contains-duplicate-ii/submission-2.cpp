class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int left{0}; left < nums.size(); left++){
            int right = left + 1;
            std::cout << right << std::endl;
            while(right <= (left + k) && right < nums.size()){
                if (nums[right] == nums[left] && right - left <= k){
                    return true;}
                else right++;
            }
        }
        return false;
    }
};