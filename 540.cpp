class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
                
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            int adjacent = adjacentfOf(nums, mid);

            if (adjacent == -1) {
                return nums[mid];
            } else if (adjacent == 0) {
                if (mid % 2 == 0) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (mid % 2 == 0) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        
        return 0;
    }
    
    int adjacentfOf(vector<int>& nums, int i) {
        if ((i - 1) >= 0 && nums[(i - 1)] == nums[i])
            return 0;
        
        if ((i + 1) < nums.size() && nums[(i + 1)] == nums[i])
            return 1;
        
        return -1;
    }
};