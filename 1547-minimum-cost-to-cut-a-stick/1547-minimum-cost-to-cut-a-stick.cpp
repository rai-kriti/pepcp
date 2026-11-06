class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = m - 2; i >= 0; i--) {

            for (int j = i + 2; j < m; j++) {

                int ans = INT_MAX;

                for (int k = i + 1; k < j; k++) {

                    int cost = cuts[j] - cuts[i]
                             + dp[i][k]
                             + dp[k][j];

                    ans = min(ans, cost);
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][m - 1];
    }
};