#include <bits/stdc++.h>

using namespace std;

 bool testBananas(vector<int> arr, int hours, int k, int len){
        
    int spent = 0;
    
    for(int i = 0; i < len; i++){
        spent += (int) (arr[i] - 1)/k + 1;
    }

    if(spent <= hours)
        return true;
    
    return false;
    
}

int minEatingSpeed(vector<int>& piles, int h) {
    
    int max,min = 1, len = piles.size();

    max = *max_element(piles.begin(), piles.end());
            
    int mid;
    
    while(min < max){
        
        mid =  min + (max - min)/2;
            
        if(testBananas(piles, h, mid, len)){
            max = mid;
        }else{
            min = mid + 1;
        }
            
    }
            
    return min;
    
}


int main(){



    return 0;

}