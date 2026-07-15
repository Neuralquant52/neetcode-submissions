class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        for (int left{0}; left < nums.size(); left++){
            int max = -18292983;
            int right = left;
            // [2,4,4,6,6,6,0]

            
            while (right < nums.size() && right - left < k){
                // std::cerr << nums[right] << std::endl;
                if (nums[right] > max) max = nums[right];
                right++;
                if (right == nums.size()) {vec.push_back(max); return vec;}
            }
            // std::cerr << "---------------" << std::endl;
            vec.push_back(max);
        }
        return vec;
    }
};
