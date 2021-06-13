class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        bool found = false;
        
        if (s == t)
            return true;
        
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == s[j])
                j++;
            
            if (j == s.length()) {
                found = true;
                break;
            }
        }
        
        return found;
    }
};