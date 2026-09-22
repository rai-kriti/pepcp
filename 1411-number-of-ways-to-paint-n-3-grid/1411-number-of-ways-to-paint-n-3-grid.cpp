

class Solution {
public:
    int numOfWays(int n) {
        long long MOD = 1e9 + 7;
        
        // Base cases for N = 1
        long long aba = 6;  // 2-color pattern
        long long abc = 6;  // 3-color pattern
        
        for (int i = 2; i <= n; ++i) {
            long long next_aba = (3 * aba + 2 * abc) % MOD;
            long long next_abc = (2 * aba + 2 * abc) % MOD;
            aba = next_aba;
            abc = next_abc;
        }
        
        return (aba + abc) % MOD;
    }
};