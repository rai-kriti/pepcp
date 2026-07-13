class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& matrix, int r, int c) {

        if (dp[r][c] != -1)
            return dp[r][c];

        int ans = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                matrix[nr][nc] > matrix[r][c]) {

                ans = max(ans, 1 + dfs(matrix, nr, nc));
            }
        }

        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        n = matrix.size();
        m = matrix[0].size();

        dp.assign(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans;
    }
};