#include <vector>

class Solution {
public:
    int countArrangement(int n) {
        // Create a memoization table for 2^(n+1) possible states.
        // Initialize with -1 to indicate uncalculated states.
        std::vector<int> memo(1 << (n + 1), -1);
        
        // Start filling from position 'n' down to 1 to maximize pruning
        return dfs(n, n, 0, memo);
    }
    
private:
    int dfs(int n, int pos, int mask, std::vector<int>& memo) {
        // Base case: If we successfully reached position 0, we found 1 valid arrangement
        if (pos == 0) return 1;
        
        // Return the cached result if we've seen this exact bitmask before
        if (memo[mask] != -1) return memo[mask];
        
        int total_arrangements = 0;
        
        for (int i = 1; i <= n; ++i) {
            // Check if the i-th bit is NOT set (meaning number 'i' is available)
            if (!(mask & (1 << i))) {
                
                // Check the beautiful arrangement mathematical condition
                if (i % pos == 0 || pos % i == 0) {
                    // Mark 'i' as used by using bitwise OR, and move to the next position
                    total_arrangements += dfs(n, pos - 1, mask | (1 << i), memo);
                }
            }
        }
        
        // Cache and return the result for this state
        return memo[mask] = total_arrangements;
    }
};