class Solution {
public:
    int checkRecord(int n) {

        const long long MOD = 1000000007;

        long long dp[2][3] = {};

        dp[0][0] = 1;

        for (int day = 1; day <= n; day++) {

            long long next[2][3] = {};

            for (int a = 0; a <= 1; a++) {
                for (int l = 0; l <= 2; l++) {

                    long long ways = dp[a][l];

                    // P
                    next[a][0] =
                        (next[a][0] + ways) % MOD;

                    // L
                    if (l < 2) {
                        next[a][l + 1] =
                            (next[a][l + 1] + ways) % MOD;
                    }

                    // A
                    if (a < 1) {
                        next[a + 1][0] =
                            (next[a + 1][0] + ways) % MOD;
                    }
                }
            }

            // Current day becomes previous day
            for (int a = 0; a <= 1; a++) {
                for (int l = 0; l <= 2; l++) {
                    dp[a][l] = next[a][l];
                }
            }
        }

        long long ans = 0;

        for (int a = 0; a <= 1; a++) {
            for (int l = 0; l <= 2; l++) {
                ans = (ans + dp[a][l]) % MOD;
            }
        }

        return ans;
    }
};