//https://leetcode.com/problems/is-subsequence/

//status: accepted
// basically just check if you get all chars from s string in t string
// just be sure that you are doind that in order

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s == t){
            return true;
        }
        if(s.size() >= t.size()){
            return false;
        }
        
        int sIndices = 0;
        int tIndices = 0;
        
        for(int i = 0; i < t.size(); i++){
            if(s[sIndices] == t[i]){
                sIndices++;
            }
        }
        
        if(sIndices == s.size()){
            return true;
        }
        
        return false;
    }
};