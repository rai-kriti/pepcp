class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[51][51][11];
    int apples[51][51];
    int m, n;

    int horizontal(int r, int c, int k) {
        int ans = 0;

        for (int i = r + 1; i < m; i++) {
            if (apples[r][c] - apples[i][c] > 0) {
                ans = (ans + solve(i, c, k - 1)) % MOD;
            }
        }

        return ans;
    }

    int vertical(int r, int c, int k) {
        int ans = 0;

        for (int j = c + 1; j < n; j++) {
            if (apples[r][c] - apples[r][j] > 0) {
                ans = (ans + solve(r, j, k - 1)) % MOD;
            }
        }

        return ans;
    }

    int solve(int r, int c, int k) {
        if (apples[r][c] == 0) return 0;
        if (k == 1) return 1;

        int &ans = dp[r][c][k];
        if (ans != -1) return ans;

        ans = (horizontal(r, c, k) + vertical(r, c, k)) % MOD;
        return ans;
    }

    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();

        memset(dp, -1, sizeof(dp));
        memset(apples, 0, sizeof(apples));

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                apples[r][c] = (pizza[r][c] == 'A');

                if (r + 1 < m)
                    apples[r][c] += apples[r + 1][c];

                if (c + 1 < n)
                    apples[r][c] += apples[r][c + 1];

                if (r + 1 < m && c + 1 < n)
                    apples[r][c] -= apples[r + 1][c + 1];
            }
        }

        return solve(0, 0, k);
    }
};