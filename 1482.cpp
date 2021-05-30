//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// if we get an random number off days, could we get how many hours bouquets we can do ?
// we can test all possible days || make an binary search

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int minDays = 1000000001;
        int maxDays = 0;
        
        
        for(int i = 0; i < bloomDay.size(); i++){ // getting lower&&bigger days
            if(bloomDay[i] > maxDays){
                maxDays = bloomDay[i];
            }
            if(bloomDay[i] < minDays){
                minDays = bloomDay[i];
            }
        }
        
        int nBouquets;
        int actualAnse = -1;
        int medium = 0;

        while(minDays <= maxDays){ // binary search
            
            medium = (maxDays+minDays)/2;   
            int nBouquest = HowMuchBouquets(medium,k,bloomDay);

            if(m <= nBouquest){   // go to left, we can try with less days
                maxDays = medium-1;
                actualAnse = medium;
              
            }else{// go to right, we should try with more days
                minDays = medium+1;
            }
            
            
        
        }
       
        
        
        return actualAnse;
    }

public:
    int HowMuchBouquets(int days,int flowers,vector<int>& bloomDay){
        int actualFlowers = 0;
        int bouquets = 0;

        for(int i = 0; i < bloomDay.size(); i++){

            if(bloomDay[i] <= days){ // count how much following flowers we have
                actualFlowers++;
            }else{
                actualFlowers = 0;
            }
            
            if(flowers == actualFlowers){ // can we make an bouquet ?
                actualFlowers = 0;   
                bouquets++;
            }
        }
        
        return bouquets;
    } 
};