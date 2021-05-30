#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums) {
    
    int l=0,r = nums.size() - 1,m;
    
    
    while(l <= r){
        
        if(l == r) return nums[l];

        m = l + (r-l)/2;
        
        if(nums[m] > nums[r]){ // o meio é maior que o seu seguinte, logo, tá na parte direita
            l = m+1;
        }else{
            r = m;
        }
        
        
    }
    
    return -1;
    
}


int main(){



    return 0;

}