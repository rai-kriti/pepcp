class Solution {
public:
    int stoneGameVII(vector<int>& stones) {

        int n = stones.size();

        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Generate intervals of increasing length
        for(int len = 2; len <= n; len++) {

            for(int l = 0; l + len <= n; l++) {

                int r = l + len - 1;

                // Remove the leftmost stone
                int leftSum = prefix[r + 1] - prefix[l + 1];
                int removeLeft = leftSum - dp[l + 1][r];

                // Remove the rightmost stone
                int rightSum = prefix[r] - prefix[l];
                int removeRight = rightSum - dp[l][r - 1];

                dp[l][r] = max(removeLeft, removeRight);
            }
        }

        return dp[0][n - 1];
    }
};