class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int left{0}; left < prices.size() - 1; left++){
            for (int right{left + 1}; right < prices.size(); right++){
                int profit = prices[right] - prices[left];
                if (profit > max_profit) max_profit = profit;
            }
        }
        return max_profit;
    }
};
