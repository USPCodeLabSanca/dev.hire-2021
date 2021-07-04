#include <stdio.h>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> sets;
    sets.push_back({}); // Storing the empty set for generating the next sets
    int n = nums.size();
    for(int num : nums){
        int currentSetSize = sets.size();
        for(int i = 0; i < currentSetSize; i++){
            vector<int> newSet = sets[i];
            newSet.push_back(num);
            sets.push_back(newSet);
        }
    }
    return sets;
}

// Time Complexity: O(n*2^n) [Exponential]
// Space Complexity: O(n*2^n) [Exponential]