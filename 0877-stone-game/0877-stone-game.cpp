class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: intervals of length 1
        for(int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Generate intervals of increasing length
        for(int len = 2; len <= n; len++) {

            for(int l = 0; l + len <= n; l++) {

                int r = l + len - 1;

                int left = piles[l] - dp[l+1][r];

                int right = piles[r] - dp[l][r-1];

                dp[l][r] = max(left, right);
            }
        }

        return dp[0][n-1] > 0;
    }
};