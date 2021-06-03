// template fera
#include <bits/stdc++.h>

#define true 1
#define false -1

#define inf 0x3f3f3f3f // numero grandão
#define ll long long

using namespace std;

typedef vector<int> vi; // vector int

typedef pair<int ,int> p_i; // pair int
typedef vector<p_i> v_p_i; // vector pair int
typedef vector<v_p_i> graph; // vector de vector pair int; (lista de adjacencia) 

void merge(vector<int> &vet,int start, int middle, int end){
    
}

void mergesort(vector<int> &vet,int start, int end){

}

int main (){

	ios :: sync_with_stdio(false);

    vector<int> unnordedvector{5,4,63,1,85,74,23,1,89,12,3,98};

    mergesort(unnordedvector,0,unnordedvector.size()-1);
    
    for(auto u: unnordedvector){
        cout << u << " - ";
    }
    cout << endl;

}