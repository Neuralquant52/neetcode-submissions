class MedianFinder {
public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top()); maxHeap.pop();

        if (maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top()); minHeap.pop();
        } 
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return static_cast<double>(maxHeap.top());
        else if (minHeap.size() > maxHeap.size()) return static_cast<double>(minHeap.top());
        else {
            return (static_cast<double>(minHeap.top()) + static_cast<double>(maxHeap.top())) / 2;
        }
    }
private:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};
