class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, std::vector<int>, std::greater<int>> heap(sticks.begin(), sticks.end());
        int sum = 0;
        while (heap.size() > 1){
            int x = heap.top(); heap.pop();
            int y = heap.top(); heap.pop();
            sum += x + y;
            heap.push(x + y);
        }


        return sum;
    }
};
