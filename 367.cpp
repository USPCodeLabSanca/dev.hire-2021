//https://leetcode.com/problems/valid-perfect-square/

// status: accepted
// basicaly we can check all numbers asking if my i number is an perfect square, but we spend O(n)
// so we will make an binary search and we can get an better time complexity solution (O(Log n))

class Solution {
public:
    bool isPerfectSquare(int num) {
        
       int start = 1;
       int end = num;
        
       while(start <= end){
           int mid = (start+end)/2;
           
           if(mid * mid == num){
            return true;
           }
           
           if(mid * mid < num){ // go to right
               start=mid+1;
               
           }else{ // got to left
               end=mid-1;
           }
           
       }
        
        return false;     
    }
};