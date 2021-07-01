
//status: TLE 
// O(n³) solution :(
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        
        int maxAcutal = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            
            
            
            for(int j = i; j < nums.size(); j++){
                
                int actualSum = 0;
                
                for(int k = i; k <= j; k++){
                    actualSum += nums[k];  
                }
                
                
                if(maxAcutal <= actualSum){                    
                    maxAcutal = actualSum;
                }
            }
        }

        return maxAcutal;
    }
};


//status: ACC
// O(n²) solution :|
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        
        int maxAcutal = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            
            int actualSum = 0;
            
            for(int j = i; j < nums.size(); j++){
                actualSum += nums[j];
                
                if(maxAcutal <= actualSum){                    
                    maxAcutal = actualSum;
                }
            }
        }

        return maxAcutal;
    }
};

//status: ACC
//O(N) and O(1)
/* every time that we see an number we just have one decision to make
   or we start a new sub array
   or we get what the best that we can do before

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums){
        
        int maxActual = nums[0];
        int bestBefore = nums[0];
            
        for(int i = 1; i < nums.size(); i++){
            
            if(bestBefore + nums[i] > nums[i]){
    
                bestBefore += nums[i];
            }else{
                bestBefore = nums[i];
            }
            
            if(bestBefore > maxActual){
                maxActual = bestBefore;
            }
            
            
        }

        return maxActual;
    }
};