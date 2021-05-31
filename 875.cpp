class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = piles[0];
        int currentMid = 1;
        
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > end)
                end = piles[i];
        }
        

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int time = this->timeToEat(piles, mid);
            
            if (time > h) {
                start = mid + 1;
            } else {
                end = mid - 1;
                currentMid = mid;
            }
        }
        
        return currentMid;
    }
    
    int timeToEat(vector<int>& piles, int k) {
        int sum = 0;
        
        for (int i = 0; i < piles.size(); i++) {
            sum += (int) ceil(((double) piles[i]) / ((double) k));
        }
        
        return sum;
    }
};