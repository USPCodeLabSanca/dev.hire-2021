class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        
        permutate(nums, nums.size(), permutations);
        
        return permutations;
    }
    
    void permutate(vector<int>& values, int size, vector<vector<int>>& permutations) {
        // Check if is a valid value
        if (size <= 0 && size > values.size())
            return;
        
        // Get permutation
        if (size == 1) {
            permutations.push_back(values);
        } else {
            // Permutate
            for (int i = 0; i < size; i++) {
                permutate(values, size - 1, permutations);
                
                if (size % 2 == 1)
                    swap(values[0], values[size - 1]);
                else
                    swap(values[i], values[size - 1]);
            }
        }
    }
};