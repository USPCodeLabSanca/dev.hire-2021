#include <bits/stdc++.h>


using namespace std;

static bool compareDistances(vector<int> p1, vector<int> p2){

    
    float d1 = sqrt(p1[0]*p1[0] + p1[1]*p1[1]);
    float d2 = sqrt(p2[0]*p2[0] + p2[1]*p2[1]);
    
    return d1 < d2;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
    vector<vector<int>> res;
    
    sort(points.begin(),points.end(), compareDistances);
    
    for(int i = 0; i < k; i ++){
        res.push_back(points[i]);
    }
    
    return res;
    
}