#include <bits/stdc++.h>


using namespace std;



int balancedStringSplit(string s) {
    
    int len = 0, sum = 0, temp = 0;
    
    
    for(int i = 0; s[i] != '\0'; i++){
        
        if(s[i] == 'L') temp--;
        if(s[i] == 'R') temp++;
        
        
        if(temp == 0) sum++;
        
    }
    
    return sum;
    
}


int main(){



    return 0;

}