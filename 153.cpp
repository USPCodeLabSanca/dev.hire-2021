class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() -1;
        int medium = (left+right)/2;
        
        while(left+1<right){
            medium = (left+right)/2;
            
            //cout << left << " - " << right << " m " << medium << endl;
            
           if(nums[medium] > nums[left] &&  nums[medium] < nums[right]){
               break;       
           }else if(! (nums[medium] > nums[left])) {
               
               right = medium;
           }else{
               left = medium+1;
           }
        }
        
        
        
        if(left+1 == right){
            return min(nums[left],nums[right]);
        }
        
        return nums[left];

    }
};
