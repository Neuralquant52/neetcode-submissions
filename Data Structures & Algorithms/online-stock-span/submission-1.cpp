class StockSpanner {
private:
    std::stack<vector<int>> prices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        if (!prices.empty()){
            while (!prices.empty() && price >= prices.top()[0]){
                span += prices.top()[1];
                prices.pop();
            }
        }
        prices.push({price, span});
        return prices.top()[1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */