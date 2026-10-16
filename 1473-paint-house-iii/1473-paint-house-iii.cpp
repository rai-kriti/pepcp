
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
                int target) {

        int INF = 1e9;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n + 1, vector<int>(target + 1, INF)));

        for (int j = 1; j <= n; j++) {
            if (houses[0] != 0 && houses[0] != j)
                continue;

            int paintCost = 0;

            if (houses[0] == 0)
                paintCost = cost[0][j - 1];

            dp[0][j][1] = paintCost;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {

                if (houses[i] != 0 && houses[i] != j)
                    continue;

                int paintCost = 0;

                if (houses[i] == 0)
                    paintCost = cost[i][j - 1];

                for (int k = 1; k <= target; k++) {

                    // Same color
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + paintCost);

                    // Different color
                    if (k > 1) {
                        for (int p = 1; p <= n; p++) {
                            if (p == j)
                                continue;

                            dp[i][j][k] = min(dp[i][j][k],
                                              dp[i - 1][p][k - 1] + paintCost);
                        }
                    }
                }
            }
        }

        int ans = INF;

        for (int j = 1; j <= n; j++) {
            ans = min(ans, dp[m - 1][j][target]);
        }

        if (ans == INF)
            return -1;

        return ans;
    }
};
