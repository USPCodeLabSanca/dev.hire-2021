//https://leetcode.com/problems/split-a-string-in-balanced-strings/

//status: accepted
// basically you could count how many R and L you get it;
// if you get an equal value, you could split your string;
class Solution {
public:
    int balancedStringSplit(string s) {

        int l = 0;
        int r = 0;
        int counter = 0;

        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == 'L'){
                l++;
            }else{
                r++;
            }
            
            if(l == r){
                counter++;
                l = 0;
                r = 0;
            }
            
        }

        return counter;
    }
};