class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i{1}; i < prices.size(); i++){
            int curr_profit = prices[i] - prices[i - 1];
            if (curr_profit <= 0) continue;
            else profit += curr_profit;
        }
        return profit;
    }
};