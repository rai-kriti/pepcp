class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int dfs(vector<vector<int>>& grid, int r, int c1, int c2) {

        // out of bounds
        if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)
            return -1000000;

        // last row
        if (r == m - 1) {
            if (c1 == c2)
                return grid[r][c1];
            else
                return grid[r][c1] + grid[r][c2];
        }

        // check memo
        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int cherries = 0;

        if (c1 == c2)
            cherries = grid[r][c1];
        else
            cherries = grid[r][c1] + grid[r][c2];

        int maxi = -1000000;

        // 9 moves
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int next = dfs(grid, r + 1, c1 + d1, c2 + d2);
                maxi = max(maxi, next);
            }
        }

        return dp[r][c1][c2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // initialize dp with -1
        dp.assign(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return dfs(grid, 0, 0, n - 1);
    }
};