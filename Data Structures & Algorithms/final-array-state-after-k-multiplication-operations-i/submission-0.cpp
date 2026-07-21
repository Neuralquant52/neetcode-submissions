class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> vec(nums.size(), 0);
    
        priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> heap;

        for (int i{0}; i < nums.size(); i++) heap.push({nums[i], i});

        for (int i{0}; i < k; i++){
            int x = heap.top().first;
            int y = heap.top().second;
            heap.pop();
            heap.push({x * multiplier, y});
        };

        while (!heap.empty()){
            vec[heap.top().second] = heap.top().first;
            heap.pop();
        }
        return vec;
    }
};