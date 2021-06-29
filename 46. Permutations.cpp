//https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        
        generatePermutations(nums, permutations, 0);
        
        return permutations;
    }
    
    //O(n!) time
    void generatePermutations(vector<int>& nums, vector<vector<int>>& permutations, int firstIndex){
        if (firstIndex == nums.size()){
            permutations.push_back(nums);
            return;
        }
        
        for (int i = firstIndex; i < nums.size(); i++){
            swap(nums[firstIndex], nums[i]);
            generatePermutations(nums, permutations, firstIndex + 1);
            swap(nums[firstIndex], nums[i]);
        }
    }
};
