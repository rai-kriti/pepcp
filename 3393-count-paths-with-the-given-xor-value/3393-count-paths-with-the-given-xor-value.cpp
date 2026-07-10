class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int f(vector<vector<int>>& grid, int r, int c, int need) {
        int n = grid.size();
        int m = grid[0].size();

        if (r == n - 1 && c == m - 1) {
            return ((grid[r][c] ^ need) == 0);
        }

        if (dp[r][c][need] != -1)
            return dp[r][c][need];

        long long ans = 0;

        int nextNeed = need ^ grid[r][c];

        if (r + 1 < n)
            ans = (ans + f(grid, r + 1, c, nextNeed)) % MOD;

        if (c + 1 < m)
            ans = (ans + f(grid, r, c + 1, nextNeed)) % MOD;

        return dp[r][c][need] = ans;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(16, -1)));

        return f(grid, 0, 0, k);
    }
};