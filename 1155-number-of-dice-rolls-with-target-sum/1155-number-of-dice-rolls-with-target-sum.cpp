class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {

        int MOD = 1000000007;

        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for (int dice = 1; dice <= n; dice++) {

            vector<int> newdp(target + 1, 0);

            for (int sum = 1; sum <= target; sum++) {

                for (int face = 1; face <= k; face++) {

                    if (sum >= face) {
                        newdp[sum] =
                            (newdp[sum] +
                             dp[sum - face]) % MOD;
                    }
                }
            }

            dp = newdp;
        }

        return dp[target];
    }
};