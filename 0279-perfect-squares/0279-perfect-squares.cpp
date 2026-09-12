
class Solution {
public:
    int numSquares(int n) {
        // dp[i] stores the minimum perfect squares needed to sum to i
        vector<int> dp(n + 1, n); // initialized to maximum possible (all 1s)
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};