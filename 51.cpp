class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> allSolutions;
        unordered_set<string> queenPlacement;
        vector<string> baseChess;
        
        // Make chess string
        for (int i = 0; i < n; i++) {
            string str(n, '.');
            
            baseChess.push_back(str);
        }
        
        // Perform the algorithm
        for (int i = 0; i < n; i++) {
            backtracking(0, i, n, n, baseChess, queenPlacement, allSolutions);
        }
        
        return allSolutions;
    }
    
    string chessVectorToString(vector<string> chess) {
        string str = "";
        
        for (int i = 0; i < chess.size(); i++) {
            str = str + chess[i] + "\n";
        }
        
        return str;
    } 
    
    void backtracking(int i, int j, int n, int size, vector<string> solution, unordered_set<string>& queenPlacement, vector<vector<string>>& allSolutions) {
        // Check if is a valid position
        if (solution[i][j] != '.')
            return;
        
        // Block positions
        // [UP, LEFT] diagonal
        for (int k = i, d = j; k >= 0 && d >= 0; k--, d--) {
            solution[k][d] = 'X';
        }
        // [UP, RIGHT] diagonal
        for (int k = i, d = j; k >= 0 && d < size; k--, d++) {
            solution[k][d] = 'X';
        }
        // [DOWN, LEFT] diagonal
        for (int k = i, d = j; k < size && d >= 0; k++, d--) {
            solution[k][d] = 'X';
        }
        // [DOWN, RIGHT] diagonal
        for (int k = i, d = j; k < size && d < size; k++, d++) {
            solution[k][d] = 'X';
        }
        
        // [UP] position
        for (int k = i, d = j; k >= 0; k--) {
            solution[k][d] = 'X';
        }
        // [DOWN] position
        for (int k = i, d = j; k < size; k++) {
            solution[k][d] = 'X';
        }
        // [LEFT] position
        for (int k = i, d = j; d >= 0; d--) {
            solution[k][d] = 'X';
        }
        // [RIGHT] position
        for (int k = i, d = j; d < size; d++) {
            solution[k][d] = 'X';
        }
        solution[i][j] = 'Q';
        
        // Check if found a valid solution
        if (n == 1) {
            queenPlacement.insert(this->chessVectorToString(solution));
            // Change X to .
            for (int k = 0; k < solution.size(); k++) {
                for (int d = 0; d < solution[k].length(); d++) {
                    if (solution[k][d] == 'X')
                        solution[k][d] = '.';
                }
            }
            allSolutions.push_back(solution);
            
            return;
        }
        
        // If not, check candidates
        for (int x = 0; x < size; x++) {
            if ((i + 1) < size && solution[(i + 1)][x] != '.')
                continue;
            
            // Continue the search
            this->backtracking(i + 1, x, n - 1, size, solution, queenPlacement, allSolutions);
            
        }
    }
};