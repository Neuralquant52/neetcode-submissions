class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> last_vec;
        for(int i{0}; i < nums.size(); i++){
            if(nums[i] != val){
                last_vec.push_back(nums[i]);
            }
        }
        nums = last_vec;
        return last_vec.size();
    }
};