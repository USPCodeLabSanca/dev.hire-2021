// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int currentMid = 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (isBadVersion(mid) == true) {
                end = mid - 1;
                currentMid = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return currentMid;
    }
};