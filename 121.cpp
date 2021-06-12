class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minBuy;
        vector<int> maxSell;
        
        int maxProfit = 0;
        
        minBuy.push_back(prices[0]);
        maxSell.push_back(prices[0]);
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minBuy[(i - 1)]) {
                minBuy.push_back(prices[i]);
                maxSell.push_back(prices[i]);
            } else {
                minBuy.push_back(minBuy[(i - 1)]);
                
                if (prices[i] > maxSell[(i - 1)]) {
                    maxSell.push_back(prices[i]);
                } else {
                    maxSell.push_back(maxSell[(i - 1)]);
                }
            }
            
            int profit = maxSell[i] - minBuy[i];
            
            if (profit > maxProfit)
                maxProfit = profit;
        }
        
        return maxProfit;
    }
};