class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                }
                else {
                    int right = INT_MAX;
                    int down = INT_MAX;

                    if (j + 1 < m)
                        right = dp[i][j + 1];

                    if (i + 1 < n)
                        down = dp[i + 1][j];

                    int needed = min(right, down) - dungeon[i][j];

                    dp[i][j] = max(1, needed);
                }
            }
        }

        return dp[0][0];
    }
};