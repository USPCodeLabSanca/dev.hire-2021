// Will prob have some erros, but could not test it on hackerank
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int knightI[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int knightJ[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 

struct {
    unordered_map<pair<int, int>, bool> visitedPlaces;
    int positionsToVisit;
    int n;
    int m;
} TestCase;

void blockCell(TestCase& tCase, int i, int j) {
    // Check if is a valid cell position
    if (!(i >= 0 && i < tCase->m && j >= 0 && j < tCase->n))
        return;
    
    // Block cell
    pair<int, int> position = make_pair(i, j);
    
    tCase->visitedPlaces[position] = true;
    tCase->positionsToVisit--;
}

bool checkIfCellIsBlocked(TestCase& case, int i, int j) {
    // Check if is a valid cell position
    if (!(i >= 0 && i < tCase->m && j >= 0 && j < tCase->n))
        return false;
    
    // Get cell
    pair<int, int> position = make_pair(i, j);
    
    if (tCase->visitedPlaces.find(position) == tCase->visitedPlaces.end())
        return false;
    
    return true;
}

vector<pair<int, int>> doTestCase(TestCase tCase, int i, int j) {
    vector<pair<int, int>> visited;
    
    // Check if cell is alredy blocked or is an invalid position
    if (checkIfCellIsBlocked(tCase, i, j))
        return visited;
    
    // If not block cell
    blockCell(&tCase, i, j);
    
    // Check if alredy visited every place
    if (tCase.positionsToVisit == 0) {
        visited.push_back(make_pair(i, j));
    } else {
        // Continue the tour
        for (int n = 0; n < 8; n++) {
            vector<pair<int, int>> childVisited;
            
            childVisited = doTestCase(tCase, i + knightI[n], j + knightJ[n]);
            
            // Check if found solution
            if (childVisited.size() > 0) {
                visited.push_back(make_pair(i, j));
                break;
            }
        }
    }
    
    return visited;
}


int main() {
    TestCase tCase;
    
    // Read the size of the chess table
    cin >> tCase.m >> tCase.n;
    
    tCase.positionsToVisit = tCase.m * tCase.n;
    
    // Number of blocked cells
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        
        cin >> x >> y;
        
        blockCell(&tCase, x, y);
    }
    
    // Do testCase
    vector<pair<int, int>> visitedPlaces = doTestCase(tCase, i, j);
    
    if (visitedPlaces.length() == 0) {
        cout << "No";
    } else {
        for (int i = visitedPlaces.size() - 1; i >= 0; i--) {
            pair<int, int> position = visitedPlaces[i];
            
            cout << pair.first << pair.second << endl;
        }
    }
    
    
    return 0;
}
