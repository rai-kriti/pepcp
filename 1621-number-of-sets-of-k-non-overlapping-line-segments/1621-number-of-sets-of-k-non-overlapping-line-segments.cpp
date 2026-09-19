class Solution {
public:
    int numberOfSets(int n, int k) {

        int N = n + k - 1;
        int R = 2 * k;
        int MOD = 1e9 + 7;

        vector<int> dp(R + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= N; i++) {

            for (int j = min(i, R); j > 0; j--) {

                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }

        return dp[R];
    }
};