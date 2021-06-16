class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxValue = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int value = sum + nums[i];            
            
            if (nums[i] >= 0) {
                value = max(value, nums[i]);
            }
            
            if (value > maxValue)
                maxValue = value;
            if (nums[i] > maxValue)
                maxValue = nums[i];
            
            sum = value;
        }

        return maxValue;
    }
};