//https://leetcode.com/problems/letter-case-permutation/
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> strings;
        string aux;
        
        generatePermutations(s, 0, aux, strings);
        
        return strings;
    }
    
    //O(2^n)
    void generatePermutations(string s, int index, string& aux, vector<string> &strings){
        if (aux.length() == s.length()){
            strings.push_back(aux);
            return;
        }
        
        if (isNumber(s[index])){
            aux += s[index];
            generatePermutations(s, index + 1, aux, strings);
            aux.pop_back();   
        } else {
            aux += tolower(s[index]);
            generatePermutations(s, index + 1, aux, strings);
            aux.pop_back();
            
            aux += toupper(s[index]);
            generatePermutations(s, index + 1, aux, strings);
            aux.pop_back();
        }
    }
    
    bool isNumber(char c){
        return c >= '0' && c <= '9';
    }
};
