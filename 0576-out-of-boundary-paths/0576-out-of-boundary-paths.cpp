class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1; // 1 way to be at the start
        
        int mod = 1e9 + 7;
        int totalPaths = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Simulate step by step
        for (int step = 1; step <= maxMove; step++) {
            // Store the state for the next move
            vector<vector<int>> next_dp(m, vector<int>(n, 0));
            
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] > 0) {
                        for (auto& d : dirs) {
                            int nr = r + d[0];
                            int nc = c + d[1];
                            
                            // If it steps out of bounds, add to our total result
                            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                                totalPaths = (totalPaths + dp[r][c]) % mod;
                            } 
                            // If it stays in bounds, push the paths to the next state
                            else {
                                next_dp[nr][nc] = (next_dp[nr][nc] + dp[r][c]) % mod;
                            }
                        }
                    }
                }
            }
            // Move to the next state
            dp = next_dp;
        }
        
        return totalPaths;
    }
};