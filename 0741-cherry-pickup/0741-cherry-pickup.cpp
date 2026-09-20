class Solution {
public:
    int getColumn(int k, int row) { return k - row; }

    bool isValid(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();

        if (row < 0 || row >= n)
            return false;

        if (col < 0 || col >= n)
            return false;

        if (grid[row][col] == -1)
            return false;

        return true;
    }

    int getCherries(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {

        int cherries = grid[r1][c1];

        // Both people are on different cells
        if (r1 != r2 || c1 != c2)
            cherries += grid[r2][c2];

        return cherries;
    }

    int getBestPrevious(vector<vector<vector<int>>>& dp, int k, int r1,
                        int r2) {

        int best = -1000000;

        // Possibility 1:
        // Person 1 came from UP
        // Person 2 came from UP
        if (r1 > 0 && r2 > 0) {
            best = max(best, dp[k - 1][r1 - 1][r2 - 1]);
        }

        // Possibility 2:
        // Person 1 came from UP
        // Person 2 came from LEFT
        if (r1 > 0) {
            best = max(best, dp[k - 1][r1 - 1][r2]);
        }

        // Possibility 3:
        // Person 1 came from LEFT
        // Person 2 came from UP
        if (r2 > 0) {
            best = max(best, dp[k - 1][r1][r2 - 1]);
        }

        // Possibility 4:
        // Person 1 came from LEFT
        // Person 2 came from LEFT
        best = max(best, dp[k - 1][r1][r2]);

        return best;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();

        int steps = 2 * n - 1;

        vector<vector<vector<int>>> dp(
            steps, vector<vector<int>>(n, vector<int>(n, -1000000)));

        // Starting point
        dp[0][0][0] = grid[0][0];

        for (int k = 1; k <= 2 * n - 2; k++) {

            for (int r1 = 0; r1 < n; r1++) {

                for (int r2 = 0; r2 < n; r2++) {

                    int c1 = getColumn(k, r1);
                    int c2 = getColumn(k, r2);

                    // Check both positions
                    if (!isValid(grid, r1, c1))
                        continue;

                    if (!isValid(grid, r2, c2))
                        continue;

                    // Find best previous possibility
                    int best = getBestPrevious(dp, k, r1, r2);

                    // No valid way to reach this state
                    if (best == -1000000)
                        continue;

                    // Cherries collected at current positions
                    int cherries = getCherries(grid, r1, c1, r2, c2);

                    dp[k][r1][r2] = best + cherries;
                }
            }
        }

        return max(0, dp[2 * n - 2][n - 1][n - 1]);
    }
};