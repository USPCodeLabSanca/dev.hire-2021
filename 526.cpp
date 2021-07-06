class Solution {
public:
    int countArrangement(int n) {
        vector<int> values;
        int quantity = 0;
        
        for (int i = 1; i <= n; i++) {
            values.push_back(i);
        }
        
        this->permutate(values, 0, quantity);
        
        return quantity;
    }
    
    void permutate(vector<int>& values, int l, int& quantity) {
        // Get permutation
        if (l == values.size()) {
            quantity++;
        } else {
            for (int i = l; i < values.size(); i++) {
                // Swap
                swap(values[l], values[i]);
                
                // Recursion call
                if (values[l] % (l + 1) == 0 || (l + 1) % values[l] == 0)
                    this->permutate(values, l + 1, quantity);
                
                // Backtrack
                swap(values[l], values[i]);
            }
        }
    }
};