//[0,2,0,3,1,0,1,3,2,1]
//[0,1,2,3,4,5,6,7,8,9]
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int current_water = 0;
        int current_num;
        for (int base{0}; base < height.size(); base++){
            if (height[base] > 0) {
                bool found_higher = false;
                for(int i{base + 1}; i < height.size(); i++){
                    current_num = i;
                    if (height[i] < height[base]) current_water += (height[base] - height[i]);
                    else if (height[i] >= height[base]){
                        water += current_water;
                        current_water = 0;
                        found_higher = true;
                        break;
                    }
                }
                if (!found_higher){
                    height[base]--;
                    base--;
                    current_water = 0;
                    continue;
                }
                base = current_num - 1;
                current_water = 0;
            } else continue;
        }
        return water;
    }
};

/*
      |
  |   || |
|_||_||||||
*/
