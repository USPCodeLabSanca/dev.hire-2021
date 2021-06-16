//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        //return maxSum(nums, left, right);
        return DPMaxSum(nums);
    }
private:
    //O(n log n) time  O(1) space
    int maxSum(vector<int>& nums, int left, int right){
        if (left == right){
            return nums[left];
        }
        
        int mid = ((unsigned int) left + right) >> 1;
            
        return max(maxSum(nums, left, mid),
                      max(maxSum(nums, mid + 1, right),
                          maxCrossingSum(nums, left, mid, right)));
    }
private:
    //O(n) time
    int maxCrossingSum(vector<int>& nums, int left, int mid, int right){
        int sum = 0;
        int firstSum = INT_MIN, secondSum = INT_MIN;
        
        //the order matters. It has to start from the end to be able to compare with the other half
        //because it is a contiguous subarray
        for (int i = mid; i >= left; i--){
            sum += nums[i];
            firstSum = max(sum, firstSum);
        }
        
        sum = 0;
        for (int i = mid + 1; i <= right; i++){
            sum += nums[i];
            secondSum = max(sum, secondSum);
        }
        
        return max(firstSum, max(secondSum, firstSum + secondSum));
    }
private:
    //O(n) time and O(1) space
    int DPMaxSum(vector<int> &nums){
        int sum = 0;
        int currentMax = INT_MIN;
        int generalMax = INT_MIN;
            
        for (int i = 0; i < (int) nums.size(); i++){
            sum += nums[i];
            
            generalMax = max(generalMax, sum);
            
            //a negative value when summed up with other value it will decrease it, 
            //so desconsider it
            if (sum < 0) sum = 0;
        }
        
        return generalMax;
    }
}; 
