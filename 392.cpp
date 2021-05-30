#include <bits/stdc++.h>


using namespace std;


bool isSubsequence(string s, string t) {

    int j = 0;
    
    for(int i = 0; i < t.length(); i++){
        if(s[j] == t[i]) j++;
    }
    
    
    if(j != s.length()) return false;
    
    return true;
    
}


int main(){




    return 0;

}