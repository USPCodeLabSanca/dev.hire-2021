//https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    //O(n) time and O(1) space, being n t.size()
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        
        if (s.empty()){
            return true;
        }
        
        while(i < s.size() && j < t.size()){
            if (s[i] == t[j]){
                i++; j++;
            } else {
                j++;
            }
            
            if (i == s.size()){
                return true;
            }
        }
        
        return false;
    }
};
