class Solution {
public:
    int dp[101][101];
    int n;
    vector<int> suffixSum;

    int solve(int i, int M) {
        if (i >= n) return 0;

        if (dp[i][M] != -1) return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int opponent = solve(i + X, max(M, X));

            int current = suffixSum[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        memset(dp, -1, sizeof(dp));

        suffixSum.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }

        return solve(0, 1);
    }
};