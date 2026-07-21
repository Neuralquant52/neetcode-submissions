class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> heap(stones.begin(), stones.end());
        while(heap.size() > 1){
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            if (x - y > 0) heap.push(x - y);
            else if (x - y < 0) heap.push(y - x);
        }
        if (heap.empty()) return 0;
        return heap.top();
    }
};
