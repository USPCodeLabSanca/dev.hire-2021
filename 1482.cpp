class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 1;
        int end = bloomDay[0];
        int currentMid = -1;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] > end)
                end = bloomDay[i];
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (this->canMakeABouquete(bloomDay, mid, k, m)) {
                end = mid - 1;
                currentMid = mid;
            } else {
                start = mid + 1;
            }
        }

        return currentMid;
    }
    
    bool canMakeABouquete(vector<int>& bloomDay, int day, int k, int m) {
        int currentK = 0;
        int mDid = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (day >= bloomDay[i])
                currentK++;
            else
                currentK = 0;
            
            if (currentK == k) {
                mDid++;
                currentK = 0;
            }
        }
        
        if (mDid >= m)
            return true;
    
        return false;
    }
};