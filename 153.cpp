class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int currentMid = nums[0];

        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
                currentMid = min(currentMid, nums[mid]);
            }
        }

        return currentMid;
    }
};