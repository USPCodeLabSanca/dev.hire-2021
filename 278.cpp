#include<bits/stdc++.h>


using namespace std;

bool isBadVersion(int version, int bad){

    if(version >= bad) return true;

    return false;

}


int firstBadVersion(int n, int bad) {
    
    int l = 1,r = n, m;
    
    
    while(l < r){
        
        
        m = l + (r-l)/2;
        
        if(isBadVersion(m,bad)){ // olhar pro lado esquerdo
            
            r = m;
            
        }else{ // olhar pro lado direito
            
            l = m + 1;
            
        }
        
    }
    
    
    return l;
        
}


int main(){



    return 0;

}