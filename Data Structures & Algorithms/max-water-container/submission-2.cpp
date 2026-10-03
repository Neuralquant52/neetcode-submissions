class Solution {
public:
    int maxArea(vector<int>& heights) {
        size_t l{};
        size_t r{heights.size() - 1};

        vector<int> vec;

        while (l < r){
            int height = std::min(heights[l], heights[r]);
            int width = r - l;
            vec.push_back(height * width);

            if (heights[r] > heights[l]) l++;
            else r--;

        }

        return *std::max_element(vec.begin(), vec.end());
    }
};
