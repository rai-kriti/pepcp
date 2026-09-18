class Solution {
    int mod = 1e9 + 7;
    int memo[51][51][51];

    int solve(int r, int c, int m, int n, int movesLeft) {
        // Base Case 1: If we step out of bounds, we found 1 valid path!
        if (r < 0 || r >= m || c < 0 || c >= n) return 1;
        
        // Base Case 2: Out of moves but still inside the grid
        if (movesLeft == 0) return 0;

        // Return cached result if already computed
        if (memo[r][c][movesLeft] != -1) return memo[r][c][movesLeft];

        //dfs
        long long paths = 0;
        paths = (paths + solve(r - 1, c, m, n, movesLeft - 1)) % mod; // Up
        paths = (paths + solve(r + 1, c, m, n, movesLeft - 1)) % mod; // Down
        paths = (paths + solve(r, c - 1, m, n, movesLeft - 1)) % mod; // Left
        paths = (paths + solve(r, c + 1, m, n, movesLeft - 1)) % mod; // Right

        return memo[r][c][movesLeft] = paths;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo, -1, sizeof(memo));
        return solve(startRow, startColumn, m, n, maxMove);
    }
};