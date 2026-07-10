class Solution {
public:
    const int MOD = 1e9 + 7;

    int f(vector<vector<int>>& grid, int r, int c, int curXor,
          int k, int n, int m,
          vector<vector<vector<int>>>& dp) {

        curXor ^= grid[r][c];

        if (r == n - 1 && c == m - 1) {
            return (curXor == k);
        }

        if (dp[r][c][curXor] != -1)
            return dp[r][c][curXor];

        long long ans = 0;

        if (r + 1 < n)
            ans = (ans + f(grid, r + 1, c, curXor, k, n, m, dp)) % MOD;

        if (c + 1 < m)
            ans = (ans + f(grid, r, c + 1, curXor, k, n, m, dp)) % MOD;

        return dp[r][c][curXor] = ans;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(16, -1)));

        return f(grid, 0, 0, 0, k, n, m, dp);
    }
};