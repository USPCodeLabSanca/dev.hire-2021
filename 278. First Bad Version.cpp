//https://leetcode.com/problems/first-bad-version/
//all the versions after a bad version are also bad and you want to find out the first bad one

class Solution {
    
public:
    //O(log n) time and O(1) space
    int firstBadVersion(int n) {
        int begin = 1, end = n;
        int firstBadVersion = 1;
        
        while (begin <= end){
            int mid = ((unsigned int) begin + (unsigned int) end) >> 1; //unsigned right shift operator
            
            //if it is a bad version, look to the previous ones to find the first
            if (isBadVersion(mid)){
                end = mid - 1;
                firstBadVersion = mid;
            } else { //if it's not, keep searching in the right half
                begin = mid + 1;
            }   
        }
        
        return firstBadVersion;
    }
};
