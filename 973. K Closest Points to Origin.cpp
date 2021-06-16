//https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    //O(n log k) time  and O(1) space
    vector<vector<int>> kClosest(vector<vector<int>> points, int k) {
        if (k == points.size()){
            return points;
        }
        
        if (k == 1){
            vector<vector<int>> ans;
            ans.push_back(*min_element(points.begin(), points.end(), comp));
            return ans;
        }
        
        partial_sort(points.begin(), points.begin() + k, points.end(), comp);
        
        return {points.begin(), points.begin() + k};
    }
    
    static bool comp(vector<int> p1, vector<int> p2){
        if (squaredDistanceFromOrigin(p1) < squaredDistanceFromOrigin(p2)){
            return true;
        }  
        
        return false;
    }
    
    static int squaredDistanceFromOrigin(vector<int> point){
        return point[0] * point[0] + point[1] * point[1]; //sqrt(distance1) > sqrt(distance2) ->  distance1 > distance2
    }
};
