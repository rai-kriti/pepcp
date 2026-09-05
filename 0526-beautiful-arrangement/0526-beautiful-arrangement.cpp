#include <vector>

class Solution {
public:
    int countArrangement(int n) {
        // max_mask represents 2^n. If n=3, max_mask = 8 (1000 in binary).
        int max_mask = 1 << n;
        
        // dp[mask] stores the number of valid arrangements for a given subset of numbers.
        std::vector<int> dp(max_mask, 0);
        
        // Base case: There is exactly 1 way to arrange an empty set of numbers.
        dp[0] = 1;
        
        // Iterate through every possible subset of numbers from 1 to (2^n - 1)
        for (int mask = 1; mask < max_mask; ++mask) {
            
            // __builtin_popcount efficiently counts the number of set bits (1s).
            // This tells us which 1-indexed position we are currently filling.
            int pos = __builtin_popcount(mask);
            
            // Try to place every available number 'i' at the current 'pos'
            for (int i = 1; i <= n; ++i) {
                
                // Check if the (i-1)-th bit is set (meaning number 'i' is in our current subset)
                if (mask & (1 << (i - 1))) {
                    
                    // Check the beautiful arrangement mathematical condition
                    if (i % pos == 0 || pos % i == 0) {
                        
                        // If valid, add the arrangements from the subproblem where 'i' was NOT included.
                        // We use XOR (^) to flip the (i-1)-th bit to 0 to look up that previous state.
                        dp[mask] += dp[mask ^ (1 << (i - 1))];
                    }
                }
            }
        }
        
        // The final answer is the state where all 'n' bits are set (e.g., 111...1)
        return dp[max_mask - 1];
    }
};