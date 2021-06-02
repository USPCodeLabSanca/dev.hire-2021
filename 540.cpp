#include<bits/stdc++.h>


using namespace std;

 int singleNonDuplicate(vector<int>& nums) {
        
    if(nums.size() == 1) return nums[0];
    
    int l=0,r = nums.size() - 1, m;
    
    if(nums[l] != nums[l+1]) return nums[l];
    
    if(nums[r] != nums[r-1]) return nums[r];
    
    while(l <= r){
        
        m = l + (r-l)/2;
        
        if(nums[m] != nums[m-1] && nums[m] != nums[m+1]) return nums[m];
        
        if(nums[m-1] == nums[m] && (m)%2 == 0 || nums[m-1] != nums[m] && (m)%2 != 0){
            
            r = m-1;
        }else{
    
            l = m+1; 
        
        }
    }
    
    
    return -1;
    
}

int main(){




    return 0;

}