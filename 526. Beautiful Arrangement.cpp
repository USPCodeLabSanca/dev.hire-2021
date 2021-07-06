//https://leetcode.com/problems/beautiful-arrangement/

class Solution {
public:
    //O(n!) time
    //O(n) space
    int countArrangement(int n) {
        vector<int> sequence = makeSequence(n);
        int quant = 0;
        
        checkPermutations(sequence, quant, 1);
        
        return quant;
    }
    
    //O(n) time
    //O(n) space
    vector<int> makeSequence(int n){
        vector<int> sequence (n + 1);
            
        for (int i = 0; i <= n; i++){
            sequence[i] = i;
        }
        
        return sequence;
    }
    
    //O(n!) time
    void checkPermutations(vector<int>& sequence, int& quant, int firstIndex){
        if (firstIndex >= sequence.size()){
            quant++;
            return;
        }
        
        for (int i = firstIndex; i < sequence.size(); i++){
            swap(sequence[firstIndex], sequence[i]);
            if (isBeautifulArrangement(sequence, firstIndex))
                checkPermutations(sequence, quant, firstIndex + 1);
            swap(sequence[firstIndex], sequence[i]);
        }
    }
    
    //O(1) time
    bool isBeautifulArrangement(vector<int> sequence, int i){
        return (sequence[i] % i == 0 || i % sequence[i] == 0);
    }
};
