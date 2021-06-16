#include <bits/stdc++.h>


using namespace std;

int maxSubArray(vector<int>& nums) {
    
    int sum = 0, res = -9999999;
    
    if(nums.size() == 1) return nums[0];
    
    for(int i = 0; i < nums.size(); i++){
        sum = sum + nums[i];
        res = max(res, sum);
        if(sum < 0) sum = 0;
        
    }
        
    return res;
    
}


int main(){




    return 0;

}