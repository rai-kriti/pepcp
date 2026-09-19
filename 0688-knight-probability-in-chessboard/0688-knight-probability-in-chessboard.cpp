class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {

        int moves[8][2] = {
            {-2, -1}, {-2, 1},
            {-1, -2}, {-1, 2},
            {1, -2},  {1, 2},
            {2, -1},  {2, 1}
        };

        vector<vector<double>> dp(n, vector<double>(n, 0));

        dp[row][column] = 1;

        for (int step = 0; step < k; step++) {

            vector<vector<double>> next(n, vector<double>(n, 0));

            for (int r = 0; r < n; r++) {

                for (int c = 0; c < n; c++) {

                    if (dp[r][c] == 0)
                        continue;

                    for (int m = 0; m < 8; m++) {

                        int nr = r + moves[m][0];
                        int nc = c + moves[m][1];

                        if (nr >= 0 && nr < n &&
                            nc >= 0 && nc < n) {

                            next[nr][nc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }

            dp = next;
        }

        double answer = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                answer += dp[r][c];
            }
        }

        return answer;
    }
};