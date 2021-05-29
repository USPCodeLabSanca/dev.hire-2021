#include<bits/stdc++.h>


using namespace std;

 bool isPerfectSquare(int num) {
        
    if(num == 1) return true;
    
    long long int l=1,r=num,mid;
    long long int square;

    
    while(l <= r){
        
        mid = l + (r-l)/2;
        square = mid*mid; 
        
        if(square==num)
            return true;
        else if(square > num)
            r = mid - 1;
        else{
            l = mid + 1;
        }
        
        
    }
    
    return false;
    
}


int main(){




    return 0;

}