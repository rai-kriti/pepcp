
class Solution {
public:
    int profitableSchemes(int n, int minProfit,
                          vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1,
                               vector<int>(minProfit + 1, 0));

        dp[0][0] = 1;

        for (int x = 0; x < group.size(); x++) {
            for (int i = n - group[x]; i >= 0; i--) {
                for (int j = minProfit; j >= 0; j--) {
                    int ni = i + group[x];
                    int nj = min(minProfit, j + profit[x]);

                    dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i <= n; i++) {
            ans = (ans + dp[i][minProfit]) % MOD;
        }

        return ans;
    }
};
