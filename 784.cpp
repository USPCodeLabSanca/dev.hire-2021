class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> allPermutations;
        
        this->permutate(0, s.length(), s, allPermutations);
        
        return allPermutations;
    }
    
    void permutate(int i, int n, string& currentString, vector<string>& allPermutations) {
        if (i == n)  {
            allPermutations.push_back(currentString);
            return;
        }
        
        if (isalpha(currentString[i])) {
            string lowerCase(currentString);
            string upperCase(currentString);

            lowerCase[i] = tolower(currentString[i]);
            upperCase[i] = toupper(currentString[i]);

            // Generate next permutations
            this->permutate(i + 1, n, lowerCase, allPermutations);
            this->permutate(i + 1, n, upperCase, allPermutations);
        } else {
            this->permutate(i + 1, n, currentString, allPermutations);
        }
    }
};