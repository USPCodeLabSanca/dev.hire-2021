class Solution {
public:
    int balancedStringSplit(string s) {
        int howMany = 0;
        
        int quantityL = 0;
        int quantityR = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'L')
                quantityL++;
            else
                quantityR++;
            
            if (quantityL == quantityR) {
                howMany++;
                quantityL = 0;
                quantityR = 0;
            }
        }
        
        return howMany;
    }
};