class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buy = prices[0];
        for (int i = 0; i < n; i++) {
            int profit = prices[i] - buy;
            maxProfit = max(maxProfit, profit);
            if (prices[i] < buy)
                buy = prices[i];
        }
        return maxProfit;
    }
};