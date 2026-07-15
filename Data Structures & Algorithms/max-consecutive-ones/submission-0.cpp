class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int streak = 0;
        vector<int> streaks; 

        for (int i{0}; i < nums.size(); ++i){
            if (nums[i] == 1){
                streak++;
            } else {
                streaks.push_back(streak);
                streak = 0;
            }
            streaks.push_back(streak);
        }
        if (!streaks.empty()){
            int max = streaks[0];
            for (int x{0}; x < streaks.size(); x++){
                if (streaks[x] >= max){
                    max = streaks[x];
                }
            }
            return max;
        } else {
            return 0;
        }
        
    }
};