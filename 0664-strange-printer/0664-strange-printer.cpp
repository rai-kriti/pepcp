class Solution {
public:
    int strangePrinter(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {

            dp[i][i] = 1;

            for (int j = i + 1; j < n; j++) {

                // Print the first a separately 1 + dp[i+1][j]
                // Don't print the first a separately every k where s[i] == s[k]:
                // dp[i+1][k-1] + dp[k][j]

                dp[i][j] = 1 + dp[i + 1][j];

                for (int k = i + 1; k <= j; k++) {

                    if (s[i] == s[k]) {

                        int cost = dp[k][j];

                        if (k > i + 1)
                            cost += dp[i + 1][k - 1];

                        dp[i][j] = min(dp[i][j], cost);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};