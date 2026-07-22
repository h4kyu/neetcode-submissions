
class Solution {
public:
    /*
    sol:
    int profit
    int maxProfit{0}
    int sell
    int buy
    iterate over prices
        if s < b
            b = s
            ++s
        else
            profit = s - b
            if profit > maxProfit
                maxProfit = profit
    return maxProfit
    */
    int maxProfit(vector<int>& prices) {
        int profit{};
        int maxProfit{0};
        size_t s{1};
        size_t b{0};
        while (s < prices.size()) {
            if (prices[s] < prices[b]) {
                b = s;
            } else {
                profit = prices[s] - prices[b];
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
            ++s;
        }

        return maxProfit;
    }
};