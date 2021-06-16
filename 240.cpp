#include <bits/stdc++.h>


using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    
    int row = 0;
    int len_x = matrix.size(), len_y = matrix[0].size();
    int col = len_y - 1;
    
    while(col >= 0 && row < len_x){
        
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) col--;
        else{
            row++;
        }
        
    } 
    
    return false;
    
}


int main(){


    return 0;
}