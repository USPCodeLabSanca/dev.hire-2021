//https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int begin = 1, end = *max_element(piles.begin(), piles.end());
        int minK = 1;
        
        if (h == piles.size()){
            return end; //Koko has to eat the maximum of bananas in one hour
        }
        
        //O(log m * n) -> m being the number of guesses and n being the number of piles
        while(begin <= end){
            int mid = ((unsigned int) begin + end) >> 1;
        
            if (testGuess(piles, mid, h) <= h){ //Koko could eat fewer bananas/hour
                end = mid - 1; //left half
                minK = mid;
            } else {
                begin = mid + 1; //right half
            }
        }
        
        return minK;
    }
private:
    //O(n) time O(1) space
    int testGuess(vector<int> piles, int guess, int h){
        int hours = 0;
        
        for(int bananas: piles){
            int div = bananas / guess;
            
            if (bananas % guess != 0){
                div++;
            }
            
            hours += div;
            
            if(hours > h) break;
        }
        
        return hours;
    }
};
