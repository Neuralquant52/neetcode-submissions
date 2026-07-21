#include <math.h>
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        std::priority_queue<int> heap(gifts.begin(), gifts.end());
        
        for (int i{0}; i < k; i++){
            int curr = std::sqrt(heap.top());
            heap.pop();
            heap.push(curr);
        }
        int sum = 0;
        while (!heap.empty()){
            sum += heap.top();
            heap.pop();
        }

        return sum;
    }
};