class KthLargest {
private:
    priority_queue<int> heap;
    int num;
public:
    KthLargest(int k, vector<int>& nums) {
        num = k;
        for (int i: nums) heap.push(i);        
    }
    
    int add(int val) {
        heap.push(val);
        priority_queue<int> copy = heap;
        for (int i{0}; i < num - 1; i++) copy.pop();
        return copy.top();
    }
};
