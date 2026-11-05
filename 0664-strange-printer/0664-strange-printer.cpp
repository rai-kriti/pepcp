class Solution {
public:

    int dp[101][101];

    int solve(int i, int j, string &s) {

        // Print the first a separately 1 + solve(i+1,j)
        // Don't print the first a separately every k where s[i] == s[k]:
        // solve(i+1,k-1)+solve(k,j)

        if (i > j) return 0;

        if (i == j) return 1;

        // Memoization: if already calculated, return stored answer
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1 + solve(i + 1, j, s);

        for (int k = i + 1; k <= j; k++) {

            if (s[i] == s[k]) {

                int cost = solve(i + 1, k - 1, s)
                         + solve(k, j, s);

                ans = min(ans, cost);
            }
        }

        // Store the answer before returning
        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {

        memset(dp, -1, sizeof(dp));

        return solve(0, s.size() - 1, s);
    }
};