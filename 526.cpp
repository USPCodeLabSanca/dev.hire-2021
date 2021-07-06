class Solution {
public:
    int countArrangement(int n) {
        vector<int> values;
        int quantity = 0;
        
        for (int i = 1; i <= n; i++) {
            values.push_back(i);
        }
        
        this->permutate(values, 0, n - 1, quantity);
        
        return quantity;
    }
    
    void permutate(vector<int>& values, int l, int r, int& quantity) {
        // Get permutation
        if (l == r) {
            bool isBeautiful = true;
        
            for (int i = 0; i < values.size(); i++) {
                if (values[i] % (i + 1) != 0 && (i + 1) % values[i] != 0) {
                    isBeautiful = false;
                    break;
                }
            }
                        
            if (isBeautiful)
                quantity++;
        } else {
            for (int i = l; i <= r; i++) {
                // Swap
                swap(values[l], values[i]);
                
                // Recursion call
                if (values[l] % (l + 1) == 0 || (l + 1) % values[l] == 0)
                    this->permutate(values, l + 1, r, quantity);
                
                // Backtrack (This step is done because we want to have O(n) on space complexity)
                swap(values[l], values[i]);
            }
        }
    }
};