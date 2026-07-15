class Solution {
public: 
    vector<int> sort(vector<int> nums){
        for (int i{1}; i < nums.size(); i++){
            int key = nums[i];
            while (i >= 1 && key < nums[i-1]){
                int num = nums[i-1];
                nums[i] = num;
                nums[i-1] = key;
                i--;
            }
        }
        return nums;
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> sorted = sort(nums);
        vector<int> streaks;
        int streak = 0;
        for (int i{0}; i < sorted.size(); i++){
            if(i+2 <= sorted.size() && sorted[i] != sorted[i+1]){
                if (sorted[i+1] - sorted[i] == 1){
                    streak++;
                } else{
                    streaks.push_back(streak);
                    streak = 0;
                }
            }
        }
        streaks.push_back(streak);
        int max_streak = *max_element(streaks.begin(), streaks.end());
        return max_streak + 1;
    }
};
