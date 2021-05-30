#include <bits/stdc++.h>


using namespace std;

int maxProfit(vector<int>& prices) {
    
    int profit, max = 0, min = 9999;
    int len = prices.size();
    
    for(int i = 0; i < len; i++){
        if(prices[i] < min)
            min = prices[i];
        else if(prices[i] - min > max)
            max = prices[i] - min;
    }
    
    
    
    return max; 
    
}



int main(){




    return 0;

}