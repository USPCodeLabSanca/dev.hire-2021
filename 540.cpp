//https://leetcode.com/problems/single-element-in-a-sorted-array/
//status: not accepted

// the way that I'm trying to do is basically do an binary search and found the lost number

// when we get an index from our array, basically we have two information about where is my lost number

// if our lost number is behind on our actual index, all the index should be like that

// 0,1 // these are the equal numbers
// 1,2
// 3,4
// 5,6

// if our lost number is ahead of our actual index, all the index should be like that

// 0,1 // these are the equal numbers
// 1,2
// 3   -> lost number
// 4,5
// 6,7


// maybe we can do somwthing based on this even/odd condition

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
                
        int left = 0;
        int right = nums.size()-1;
        int medium;
        
        
        
        while(left <= right){
            cout << "this is the medium ";
            cout << nums[medium] << endl;
            medium = (left + (right- left)) / 2;
            
            if(medium % 2 == 0){ // we have even number
                
                if(nums[medium] == nums[medium+1]){ // go to right
                    left = medium+1;     
                    
                }else{ // go to left
                    
                    if(nums[medium] != nums[medium-1]){
                        
                        return nums[medium];
                    }else{
                       right = medium-1;  
                    }
                        
                    
                }
                
            }else{
                
                if(nums[medium-1] == nums[medium]){
                    left = medium+1; 
                }else{
                    
                    if(nums[medium] != nums[medium+1]){
                        
                        return nums[medium];
                    }else{
                       right = medium-1;  
                    }
                }    
            }
            
            
        }
        
        
        return nums[medium];
    }
};