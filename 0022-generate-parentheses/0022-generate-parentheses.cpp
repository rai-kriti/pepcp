#pragma GCC optimize("O3", "unroll-loops")

class Solution {
public:
    vector<string> generateParenthesis(int totalPairs) {
        // Hardcoded sizes based on mathematical Catalan numbers for n = 0 to 8
        const int exactSizes[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430};
        
        vector<string> allCombinations;
        allCombinations.reserve(exactSizes[totalPairs]); // Reserve memory just once
        
        // The final string will always have exactly (2 * totalPairs) characters
        string currentString(2 * totalPairs, ' ');
        
        // Start the recursive building process
        buildCombinations(allCombinations, currentString, 0, 0, 0, totalPairs);
        
        return allCombinations;
    }
    
private:
    void buildCombinations(vector<string>& allCombinations, string& currentString, 
                           int position, int openCount, int closeCount, int totalPairs) {
        
        // Base case: If we have filled the string, save it and go back
        if (position == 2 * totalPairs) {
            allCombinations.push_back(currentString);
            return;
        }
        
        // Option 1: Add an opening bracket '(' if we still have some left to use
        if (openCount < totalPairs) {
            currentString[position] = '(';
            buildCombinations(allCombinations, currentString, position + 1, openCount + 1, closeCount, totalPairs);
        }
        
        // Option 2: Add a closing bracket ')' if there are open brackets waiting to be closed
        if (closeCount < openCount) {
            currentString[position] = ')';
            buildCombinations(allCombinations, currentString, position + 1, openCount, closeCount + 1, totalPairs);
        }
    }
};