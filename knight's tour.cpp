#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<int,int>> currentPath;
vector<pair<int,int>> bestPath;
bool visited[8][8];
int ways[8][2] = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2},
                  {2, -1}, {1, -2}, {-2, -1}, {-1, -2}};

bool isValidPosition(int x, int y, int m, int n){
    return x < m && x >= 0 && y < n && y >= 0 && !visited[x][y];
}

void updatePath(){
    if (bestPath.empty()){
        bestPath = currentPath;
    }
    
    for (int i = 0; i < currentPath.size(); i++){
        if (currentPath[i].first < bestPath[i].first){
            bestPath = currentPath;
            return;
        }
        
        if (currentPath[i].first == bestPath[i].first && currentPath[i].second < bestPath[i].second){
            bestPath = currentPath;
            return;
        }
    }
}

void findPath(int currI, int currJ, int m, int n, int b){
    for (int i = 0; i < 8; i++){
        int x = currI + ways[i][0];
        int y = currJ + ways[i][1];
        if (isValidPosition(x, y, m, n)){
            visited[x][y] = true;
            currentPath.push_back({x,y});
             cout << x << " " << y << endl;
            if (currentPath.size() == m * n - b){
                updatePath();
            } else {
                findPath(x, y, m, n, b);
            }
            visited[x][y] = false;
            currentPath.pop_back();
        }
    }
}

void markBlockedCells(vector<pair<int,int>> blockedCells){
    for (auto cell: blockedCells){
        visited[cell.first][cell.second] = true;
    }
}

int main() {
    int m, n, b;
    vector<pair<int,int>> blockedCells;

    cin >> m >> n;
    cin >> b;

    blockedCells.resize(b);

    for (int i = 0; i < b; i++){
        cin >> blockedCells[i].first >> blockedCells[i].second;
    }

    markBlockedCells(blockedCells);

    visited[0][0] = true;
    currentPath.push_back({0,0});
    findPath(0, 0, m, n, b);

    if (bestPath.empty()){
        cout << "No" << endl;
    } else {
        for (int i = 0; i < bestPath.size(); i++){
            cout << bestPath[i].first << " " << bestPath[i].second << endl;
        }
    }

    return 0;
}
