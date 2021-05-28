//https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined on problem.

//status: accepted
// basicaly we can check all numbers asking if my i number is an bad version, but we spend O(n)
// so we will make an binary search and we can get an better time complexity solution (O(Log n))

class Solution {
public:
    int firstBadVersion(int n) {
        
        int left = 1;
        int right = n;
        int lastBadVersion;
        
        while(left <= right){
            // doing that to not overflow int variable with (left+right)/2
            int medium = left + (right - left) / 2;
            
            if(isBadVersion(medium)){
                lastBadVersion = medium;
                right = medium-1;
            }else{
                
                left = medium+1;
                
            }
        }
        
        return lastBadVersion;
        
    }
};


