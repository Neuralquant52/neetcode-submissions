class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap(nums.begin(), nums.end());
        for (int i{1}; i < k; i++) heap.pop();

        return heap.top();
    }
};
// 1 1 2 3 4 5 5 
// 1 2 3 4 5