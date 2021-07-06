//https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        
        subsets.push_back(subset);
        
        generateSubsets(nums, subsets, 0, subset);
        
        return subsets;
    }
    
    //O(2^n) time
    void generateSubsets(vector<int> &nums, vector<vector<int>>& subsets, int firstIndex, vector<int>& subset){
        for (int i = firstIndex; i < nums.size(); i++){
            subset.push_back(nums[i]);
            subsets.push_back(subset);
            generateSubsets(nums, subsets, i + 1, subset);
            subset.pop_back();
        }
    }
};
