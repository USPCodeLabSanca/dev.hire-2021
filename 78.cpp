class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<vector<int>> bitStrings;
        
        // Generate bit strings for powerset algoirithm
        vector<int> baseBitString(nums.size(), 0);
        generateBitString(0, nums.size(), baseBitString, bitStrings);
        
        // Generate power set based on bit strings
        for (int i = 0; i < bitStrings.size(); i++) {
            vector<int> subset;
            
            for (int j = 0; j < bitStrings[i].size(); j++) {
                if (bitStrings[i][j] == 1)
                    subset.push_back(nums[j]);
            }
            
            powerSet.push_back(subset);
        }
        
        return powerSet;
    }
    
    void generateBitString(int i, int n, vector<int>& currentBitString, vector<vector<int>>& allBitStrings) {
        if (i == n)  {
            allBitStrings.push_back(currentBitString);
            return;
        }
        
        vector<int> bit0(currentBitString);
        vector<int> bit1(currentBitString);
        
        bit0[i] = 0;
        bit1[i] = 1;
        
        // Generate next bit strings
        generateBitString(i + 1, n, bit0, allBitStrings);
        generateBitString(i + 1, n, bit1, allBitStrings);
    }
};