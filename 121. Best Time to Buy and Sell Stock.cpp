//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    //O(n) time and O(1) space
    int maxProfit(vector<int>& prices) {
        int currentMinimum = INT_MAX;
        int maxProfit = 0;
        
        //The greater profit will always include the current minimum
        for (int price: prices){
            if (price < currentMinimum){
                currentMinimum = price;
            } else {
                maxProfit = max(price - currentMinimum, maxProfit);   
            }
        }
        
        return maxProfit;
    }
};
