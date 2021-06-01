//https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
public:
    //O(n) time and O(1) space
    int balancedStringSplit(string s) {
        int ans = 0;
        char first_letter = s[0];
        int counter = 0;
        
        for (int i = 0; i < s.length(); i++){
            if (s[i] == first_letter){
                counter++;
            } else {
                counter--;
            }
            
            if (counter == 0){
                ans++;
                if (i + 1 < s.length())
                    first_letter = s[i + 1];
            }
        }
        
        return ans;
    }
};
