class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int mod = 1e9 + 7;

        int dp[51][51][101] = {};

        for (int x = 1; x <= m; x++) {
            dp[1][1][x] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int cost = 1; cost <= k; cost++) {
                for (int maxVal = 1; maxVal <= m; maxVal++) {

                    if (dp[i][cost][maxVal] == 0)
                        continue;

                    // Case 1: New element <= current maximum
                    dp[i + 1][cost][maxVal] =
                        (dp[i + 1][cost][maxVal] +
                         1LL * dp[i][cost][maxVal] * maxVal) % mod;

                    // Case 2: New element > current maximum
                    for (int x = maxVal + 1; x <= m; x++) {
                        dp[i + 1][cost + 1][x] =
                            (dp[i + 1][cost + 1][x] +
                             dp[i][cost][maxVal]) % mod;
                    }
                }
            }
        }

        int ans = 0;

        for (int maxVal = 1; maxVal <= m; maxVal++) {
            ans = (ans + dp[n][k][maxVal]) % mod;
        }

        return ans;
    }
};