class Solution {
public:
    const long long MOD = 1000000007;

    long long dp[100001][2][3];

    long long solve(int n, int absent, int consecutive_late) {

        if (n == 0)
            return 1;

        if (dp[n][absent][consecutive_late] != -1)
            return dp[n][absent][consecutive_late];

        long long A = 0;
        long long L = 0;
        long long P = 0;

        // Choose A
        if (absent < 1) {
            A = solve(n - 1, absent + 1, 0);
        }

        // Choose L
        if (consecutive_late < 2) {
            L = solve(n - 1, absent, consecutive_late + 1);
        }

        // Choose P
        P = solve(n - 1, absent, 0);

        return dp[n][absent][consecutive_late] =
            (A + L + P) % MOD;
    }

    int checkRecord(int n) {

        memset(dp, -1, sizeof(dp));

        return solve(n, 0, 0);
    }
};