class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        auto maxProfit{0};
        auto minBuy{prices[0]};
        for (size_t i{1}; i < prices.size(); i++) {
            if (prices[i-1] < minBuy) {
                minBuy = prices[i-1];
            }
            auto profit{prices[i] - minBuy};
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};
