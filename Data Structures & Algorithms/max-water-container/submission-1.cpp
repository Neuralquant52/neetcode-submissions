class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        vector<int> areas;
        while (left < right){
            areas.push_back(std::min(heights[left], heights[right]) * (right - left));
            if (heights[left] < heights[right]) left++;
            else if (heights[left] > heights[right]) right--;
            else {
                right--;
                left++;
            }
        }
        

        int max = areas[0];
        for (int i : areas){
            if (i > max) max = i;
        }

        return max;
    }
};
