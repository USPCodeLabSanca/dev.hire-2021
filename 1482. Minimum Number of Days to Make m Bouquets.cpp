//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        unsigned int totalNumberFlowers = m * k;
        
        if (totalNumberFlowers > bloomDay.size()){
            return -1;
        }
        
        if (totalNumberFlowers == 1){
            return *min_element(bloomDay.begin(), bloomDay.end());
        }
        
        if (totalNumberFlowers == bloomDay.size()){
            return *max_element(bloomDay.begin(), bloomDay.end());
        }
        
        int begin = 1, end = *max_element(bloomDay.begin(), bloomDay.end());
        int minimum = 1;
    
        //(O log m * n) time -> being m the number of guesses and n the number of bloom days
        //O(1) space
        while(begin <= end){
            int mid = ((unsigned int) begin + end) >> 1;
            int remainingBouquets = testGuess(bloomDay, m, k, mid);
            
            if(remainingBouquets > 0){ //should wait more
                begin = mid + 1;
            } else { //could wait less
                minimum = mid;
                end = mid - 1;
            }
        }
        
        return minimum;
    }
    
private:
    //O(n) time and O(1) space
    int testGuess(vector<int> bloomDay, int quantBouquets, int quantFlowers, int guess){
        int currQuantFlowers = quantFlowers;
        
        for (int day: bloomDay){
            if (guess - day >= 0){
                currQuantFlowers--;
            } else { //it couldn't makes a bouquet with adjacent flowers, so restart the count
                currQuantFlowers = quantFlowers;
            }
            
            //it could makes a bouquet, so try make the next
            if (currQuantFlowers == 0){
                quantBouquets--;
                currQuantFlowers = quantFlowers;
            }
            
            if (quantBouquets == 0){
                break;
            }
        }
        
        return quantBouquets;
    }
};
