class MyStack {
public:
    int arr[100];
    int* ptr = &arr[0];
    int size = 0;
    MyStack() {
        
    }
    
    void push(int x) {
        *(ptr + size) = x;
        size++;
    }
    
    int pop() {
        std::cout << size << std::endl;
        int val = *(ptr+size-1);
        size--;
        return val;
    }
    
    int top() {
        int val = *(ptr+size-1);
        std::cout << val << std::endl;
        return val;
    }
    
    bool empty() {
        bool result;
        size == 0? result = true: result = false;
        return result;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */