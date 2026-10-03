class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, int> data_;
        for (int x{}; x < nums.size(); x++){
            data_[nums[x]]++;
            if (data_[nums[x]] >= 2) return true;
        }
        return false;
    }
};