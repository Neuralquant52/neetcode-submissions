class MinStack {
public:
    vector<int> vec; 
    MinStack() {
        
    }
    
    void push(int val) {
        vec.push_back(val);
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    //1, 2, -2, -1, -2, 2
    int getMin() {

        int min = vec[0];
        for (auto i{0}; i < vec.size(); i++){
            if (vec[i] <= min){
                min = vec[i];
            }
        }
        return min;
    }
};
