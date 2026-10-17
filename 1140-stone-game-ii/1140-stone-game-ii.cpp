class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffixSum(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }

        int dp[101][101] = {};

        for (int i = n - 1; i >= 0; i--) {
            for (int M = n; M >= 1; M--) {

                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    int opponent = dp[i + X][max(M, X)];

                    int current = suffixSum[i] - opponent;

                    dp[i][M] = max(dp[i][M], current);
                }
            }
        }

        return dp[0][1];
    }
};