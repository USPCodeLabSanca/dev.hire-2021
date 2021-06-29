//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//status: accepted
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int min = 10005;
       int maxProfit = 0;
        
        
        for(int i = 0; i < prices.size() ; i++ ){
            if(prices[i] < min){
                min  = prices[i];
            }else if(maxProfit < prices[i] - min){
                maxProfit =  prices[i] - min;
            }
        }
        
        return maxProfit;
    }
};