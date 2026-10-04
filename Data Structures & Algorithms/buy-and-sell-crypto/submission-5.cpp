class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int max_{};
        int L{};
        int R{L+1};
        for (; R < prices.size() - 1; R++){
            if (prices[R] < prices[L]){
                L = R;
            } 
            else max_ = std::max(max_, prices[R] - prices[L]);
        }
        max_ = std::max(max_, prices[R] - prices[L]);

        return max_;
    }
};
