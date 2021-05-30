//https://leetcode.com/problems/koko-eating-bananas/


//status: accepted
// if we get an random number off bananas, could we get how many hours koko will spent ?
// we can test all possible numbers || make an binary search

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxBananas = -1;
        int minBananas = 1;
        
        for(int i = 0; i < piles.size(); i++){ // getting the bigger pile 
            if(piles[i] > maxBananas){
                maxBananas = piles[i]; 
            } 
        }
        
        int minAnserw = maxBananas;
        int medium;
        
        if(piles.size() == h){ // that means we have just an hour per pile, so we have to eat the bigger one
            return maxBananas;
        }

        while(minBananas <= maxBananas){ // binary search
            
            medium = (minBananas+maxBananas)/2; // get the medium one

            int hours = howMuchHours(piles,medium); // calculate how many hours we spent with (medium) numbers off bananas
            
            if(hours > h){ // we should eat more bananas, go to right
                minBananas = medium + 1;
            }else{ // we can eat less bananas, go to left
                maxBananas = medium-1;
            }
            
        }
        
        
        return minBananas;    
    }
    
    
    int howMuchHours(vector<int>& piles,int bananas){ 
        
        int hours = 0;
        
        for(int i = 0; i< piles.size(); i++){
            hours += piles[i]/bananas;
            
            if(piles[i]%bananas != 0){
                hours++;
            }
        }
        
        return hours;
    }
};