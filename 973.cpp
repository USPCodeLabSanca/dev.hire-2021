//#define DEBUG

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        this->mergeSort(points, 0, points.size() - 1);
        
        vector<vector<int>> kPoints(points.begin(), points.begin() + k);
        
        return kPoints;
    }
    
    void mergeSort(vector<vector<int>>& points, int l, int r) {
        if (l < r) {
            #ifdef DEBUG
            cout << "mergeSort:" << l << ", " << r << endl;
            #endif
            
            float mid = l + (r - l) / 2;

            this->mergeSort(points, l, mid);
            this->mergeSort(points, mid + 1, r);
            this->merge(points, l, mid, r);
        }
    }
    
    double calculateDistance(vector<int> point) {
        double x = pow(point[0], 2);
        double y = pow(point[1], 2);
        
        return sqrt(x + y);
    }
    
    void merge(vector<vector<int>>& points, int l, int m, int r) {
        vector<vector<int>> A;
        vector<vector<int>> B;
        
        for (int i = 0; i < ((m - l) + 1); i++) {
            A.push_back(points[l + i]);
        }
        for (int i = 0; i < (r - m); i++) {
            B.push_back(points[m + 1 + i]);
        }
        
        #ifdef DEBUG
        cout << "A" << endl;
        for (int i = 0; i < A.size(); i++) {
          cout << A[i][0] << "," << A[i][1] << endl;  
        }
        
        cout << "B" << endl;
        for (int i = 0; i < B.size(); i++) {
          cout << B[i][0] << "," << B[i][1] << endl;  
        }
        
        cout << "i" << "\t\t" << "j" << "\t\t" << "vA?vB" << endl;
        #endif
        
        int i = 0;
        int j = 0;
        int k = l;
        
        while (i < A.size() && j < B.size()) {
            double valA = this->calculateDistance(A[i]);
            double valB = this->calculateDistance(B[j]);
            
            #ifdef DEBUG
            cout << i << "\t\t" << j << "\t\t" << valA << "?" << valB <<  endl;
            #endif
            
            if (valA <= valB) {
                points[k] = A[i];
                i++;
            } else {
                points[k] = B[j];
                j++;
            }
            
            k++;
        }
        
        while (i < A.size()) {
            points[k] = A[i];
            k++;
            i++;
        }
        
        while (j < B.size()) {
            points[k] = B[j];
            k++;
            j++;
        }
        
    }
};