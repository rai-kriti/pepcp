class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    const int M = 1e9 + 7;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, 0)));

        for(int k = 1; k <= maxMove; k++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    for(auto &ele : dir){
                        int new_r = i + ele[0];
                        int new_c = j + ele[1];

                        if(new_r < 0 || new_r >= m || new_c < 0 || new_c >= n) {
                            dp[i][j][k] = (dp[i][j][k] + 1) % M;
                        } else {
                            dp[i][j][k] = (dp[i][j][k] + dp[new_r][new_c][k-1]) % M;
                        }
                    }
                }
            }
        }

        return dp[startRow][startColumn][maxMove];
    }
};