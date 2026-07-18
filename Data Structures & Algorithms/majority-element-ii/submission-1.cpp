class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> vec;
        int arr[1000] = {0};
        for (int i{0}; i < nums.size(); i++){
            arr[nums[i]]++;
        }
        for (int i{0}; i < sizeof(arr) / 4; i++){
            if (arr[i] > nums.size() / 3) vec.push_back(i);
        }
        return vec;
    }
};