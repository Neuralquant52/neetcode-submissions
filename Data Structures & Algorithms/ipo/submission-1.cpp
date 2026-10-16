class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> minHeap;
        priority_queue<int> maxHeap;

        for (int i{}; i < profits.size(); i++) minHeap.push({capital[i], profits[i]});
        
        for (int i{}; i < k; i++){
            while (!minHeap.empty() && minHeap.top().first <= w){
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
    
            if (!maxHeap.empty()) w += maxHeap.top(), maxHeap.pop();
        }
        
        return w;
    }
};