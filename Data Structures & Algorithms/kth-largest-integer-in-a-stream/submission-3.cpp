class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : x(k) {
        for (int i : nums) heap.push(i);
    }
    
    int add(int val) {
        heap.push(val);
        auto copy = heap;
        for (int i{}; i < x-1; i++) copy.pop();
        return copy.top();
    }

private:
    int x;
    priority_queue<int> heap;
};
