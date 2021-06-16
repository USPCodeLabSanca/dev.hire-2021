//https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //O(m log n) time    O(1) space
        /*for (int i = 0; i < (int) matrix.size(); i++){
            if (binarySearch(matrix[i], target)){
                return true;
            }
        }*/
        
        //return false;
        //return diagonalBinarySearch(matrix, target);
        return searchRecursively(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
    
    //O(log n) time    O(1) space
    bool binarySearch(vector<int> row, int target){
        int begin = 0, end = row.size() - 1;
          
        if (row[end] < target){
            return false;
        }
        
        if (row[begin] > target){
            return false;
        }
        
        while (begin <= end){
            int mid = ((unsigned int) begin + end) >> 1;
            
            if (row[mid] == target){
                return true;
            }
            
            if (row[mid] < target){
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return false;
    }
    
    //O(n + m) time   O(1) space
    bool diagonalBinarySearch(vector<vector<int>>& matrix, int target){
        int i = 0, j = matrix[i].size() - 1;
        
        while (i < matrix.size() && j >= 0){
            if (matrix[i][j] == target){
                return true;
            }
            
            //go down
            if (matrix[i][j] < target){
                i++;
            } else { //go to the left
                j--;
            }
        }
        
        return false;
    }
    
    bool searchRecursively(vector<vector<int>>& matrix, int target, int top, int bottom, int left, int right){
        if (top > bottom || left > right){
            return false;
        }
        
        int rowMid = ((unsigned int) top + bottom) >> 1;
        int columnMid = ((unsigned int) left + right) >> 1;
        
        if (matrix[rowMid][columnMid] == target){
            return true;
        }
        
        if (matrix[rowMid][columnMid] > target){
                    //numbers above the central
            return searchRecursively(matrix, target, top, rowMid - 1, left, right) ||
                    //numbers from the central unto the bottom, to the left of the central
                    searchRecursively(matrix, target, rowMid, bottom, left, columnMid - 1);
        } else {
                   //numbers from the top unto the central, to the right of the central
            return searchRecursively(matrix, target, top, rowMid, columnMid + 1, right) ||
                //numbers below the central
                searchRecursively(matrix, target, rowMid + 1, bottom, left, right);
        }   
    }
};
