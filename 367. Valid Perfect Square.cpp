//https://leetcode.com/problems/valid-perfect-square/
//Given a positive integer num, write a function which returns True if num is a perfect square else False.

class Solution {
public:
    //O(log n) time and O(1) space
    bool isPerfectSquare(int num) {
        int begin = 1, end = num;
        
        while (begin <= end){
            int mid = ((unsigned int) begin + (unsigned int) end) >> 1; //shift 1 bit to the right
            
            //mid² = num, therefore, is perfect square
            if (mid == num / (double) mid){
                return true;
            }
            
            //mid² > num, so choose a smaller mid
            if (mid > num / (double) mid){
                end = mid - 1;
            } else {
                begin = (mid == INT_MAX) ? mid : mid + 1;
            }
        }
        
        return false;
    }
};
