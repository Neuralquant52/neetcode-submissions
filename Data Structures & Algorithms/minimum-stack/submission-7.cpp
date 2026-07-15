class MinStack {
public:
    int test[1000];
    int* p = &test[0]; 
    int current_size = 0;    
    MinStack() {
  
    }
    
    void push(int val) {
        *(p + current_size) = val;
        current_size++;
        std::cout << current_size<< std::endl;
    }
    /*
    1
    2
    3
    3
    1
    */
    void pop() {
        *(p + current_size) = 0;
        current_size--;
    }
    
    int top() {
        return *(p + current_size-1);

    }
    int getMin() {
        int min = *p;
        for (auto i{0}; i < current_size; i++){
            int value = *(p+i);
            if (value <= min){
                min = value;
            }
        }
        return min;
    }
};
