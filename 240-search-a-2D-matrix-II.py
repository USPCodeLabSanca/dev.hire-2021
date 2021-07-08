'''
Approach for my first idea:

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


'''
Approach for a better idea:

If we start at [0][0] position and its value is smaller than our target, then we need to either go down
or go right to look for our target. So, we have 2 paths to search. And at each one of this paths, we could
have anothe 2 paths to search, and so on. That's the efficiency problem of our first approach, increasing
our recursion call stack even though we're keeping track of which positions we already visited.

A better approach would consider to start, for example, at [0][lastColumn] position. This way, if its
value is greater than our target, we only have one option: go left. If its value is smaller we also
have only one option: go down. This way, we now have only one path to "explore" at each position if its
value its different from our target and that can significantly increase the efficiency of our search.

Not just that, but now, having only one path to explore at ay case, we can easily transform our recursion
algorithm in a simple iterative algorithm, reducing the space complexicity. To make things even better, 
since we're exploring only one path each time, there's no risk of revisiting a position again, and we don't
need the auxiliar set anymore. This elegant solution abuses from the fact that every row and column are 
sorted, has a time complexity of O(logN) average and space complexicity O(1).

'''


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        row = 0
        column = len(matrix[0]) - 1
        
        while row < len(matrix) and column >= 0:
            
            currentValue = matrix[row][column]
            
            if currentValue == target:
                return True
            elif currentValue > target:
                column -= 1
            elif currentValue < target:
                row += 1
        
        return False