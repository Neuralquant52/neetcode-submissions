class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int x = 0;
        int y = heights.size() - 1;
        while (x < y){
            int delta = (y - x);
            std::cout << x << " : " << heights[x] << " | " << y << " : " << heights[y] << " | " << delta << std::endl;
            if (std::min(heights[y], heights[x]) * delta > max){
                max = std::min(heights[x], heights[y]) * delta;
            } else {
                if (heights[x] < heights[y]) x++;
                else y--;
            }
        }
        return max;
    }
};
