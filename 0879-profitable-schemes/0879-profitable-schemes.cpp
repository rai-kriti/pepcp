
class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[101][101][101];

    int solve(int i, int members, int prof, int n, int minProfit,
              vector<int>& group, vector<int>& profit) {

        if (i == group.size()) {
            return prof == minProfit ? 1 : 0;
        }

        if (dp[i][members][prof] != -1) {
            return dp[i][members][prof];
        }

        // Skip current crime
        int ans = solve(i + 1, members, prof, n, minProfit,
                        group, profit);

        // Take current crime
        if (members + group[i] <= n) {
            int newProfit = min(minProfit, prof + profit[i]);

            ans = (ans + solve(i + 1, members + group[i],
                               newProfit, n, minProfit,
                               group, profit)) % MOD;
        }

        return dp[i][members][prof] = ans;
    }

    int profitableSchemes(int n, int minProfit,
                          vector<int>& group, vector<int>& profit) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, n, minProfit, group, profit);
    }
};
