class Solution {
public:
    int m, n;
    
    int dfs(int i, int j, vector<vector<int>>& grid) {
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        
        int gold = grid[i][j];
        
        // mark visited
        grid[i][j] = 0;
        
        int best = 0;
        
        best = max(best, dfs(i + 1, j, grid));
        best = max(best, dfs(i - 1, j, grid));
        best = max(best, dfs(i, j + 1, grid));
        best = max(best, dfs(i, j - 1, grid));
        
        // unmark / backtrack
        grid[i][j] = gold;
        
        return gold + best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (grid[i][j] != 0)
                    ans = max(ans, dfs(i, j, grid));
            }
        }
        
        return ans;
    }
};