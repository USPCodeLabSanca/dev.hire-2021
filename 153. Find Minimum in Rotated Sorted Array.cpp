//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        
        int begin = 0, end = nums.size() - 1;
        
        //it's rotated n times, that is, with no effect
        if (nums[begin] < nums[end]){
            return nums[begin];
        }
        
        //it's the first of the sequence in ascending order
        if (nums[end] < nums[end - 1]){
            return nums[end];
        }
        
        //O(log n) time being n the nums.size()
        //O(1) space complexity
        while (begin <= end){
            int mid = ((unsigned int) begin + end) >> 1;
            
            if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1]){
                return nums[mid];
            }
            
            if (nums[mid] > nums[end]){ //the smaller numbers are in the right half
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return -1; //error
    }
};
