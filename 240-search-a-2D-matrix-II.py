'''
Approach idea:

    1 - We're always gonna 'abuse' the fact that each row and column are sorted in ascending order
    2 - If every row and column are sorted in ascending order, it's possible to prove that every diagonal 
        (from upper left to bottom right) is also sorted in ascending order
    3 - In this algorithm, we prefer to start checking the upper leftmost element (the smaller one)
    
    4 - If the current position is valid and not visited yet:
    
            If the value of our current position is greater than the target value
                check its left position
                check its upper position
                
            If the value of our current position is smaller than the target value:
                check the next diagonal element
        
            If the value of our current position is the target value:
                return True
                
        If the current position is not valid or was already visited:
                return False
        
    5 - A 'invalid' position is a position that is out of bounds
    6 - Remember to always save in an auxiliar set the positions that we've already visited
            
    
'''

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        visited = set()
        return self.checkValue(matrix, target, 0, 0, visited)
    
    
    def checkValue(self, matrix, target, row, column, visited):
        
        if not self.valid(matrix, row, column) or (row, column) in visited:
            return False
        
        currentValue = matrix[row][column]
                
        if currentValue > target:
            visited.add((row, column))
            return self.checkValue(matrix, target, row, column - 1, visited) or self.checkValue(matrix, target, row - 1, column, visited)
        
        elif currentValue < target:
            visited.add((row, column))
            return self.checkValue(matrix, target, row + 1, column + 1, visited)  or self.checkValue(matrix, target, row, column + 1, visited) or self.checkValue(matrix, target, row + 1, column, visited)
        
        else:
            return True
       
    
    def valid(self, matrix, row, column):
        
        rows = len(matrix)
        columns = len(matrix[0])
        return (row >= 0 and row < rows and column >= 0 and column < columns)
