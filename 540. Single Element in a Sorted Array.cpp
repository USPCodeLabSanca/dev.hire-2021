//https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        
        //treating the corner cases
        if (nums.size() == 1){
            return nums[0];
        }
        
        if (nums[begin] != nums[begin + 1]){
            return nums[begin];
        }
        
        if (nums[end] != nums[end - 1]){
            return nums[end];
        }
        
        //it's certainly in the middle between two pairs, so use binary search
        while(begin <= end){
            int mid = ((unsigned int) begin + (unsigned int) end) >> 1;
        
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]){
                return nums[mid];
            }
            
            //if position is odd, the left half size is odd, so if number[pos] == number[pos+1]
            //as left half size is odd with different numbers, the single element is there
            //example 1,1,2,3,3,4,4,8,8    the middle is pos 3 -> odd
            //number[3] == number[4], so in the left half 1,1,2 there is the single element
            
            //if the position is even, the left half size is even, so if number[pos] == number[pos - 1],
            //the left half size without the previous (pos - 1) is odd with different numbers, so the single element is there
            //example 6,6,8,8,7,7,10,11,11    the middle is pos 4 -> even
            //number[4] != number[3], so in the right half 7,10,11,11 there is the single element
            
            if (mid % 2 != 0 && nums[mid] == nums[mid+1]
               || mid % 2 == 0 && nums[mid] == nums[mid - 1]){
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        
        return -1; //error
    }
};
