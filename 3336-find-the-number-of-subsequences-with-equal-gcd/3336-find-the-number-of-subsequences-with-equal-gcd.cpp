class Solution {
public:
    int mod = 1e9 + 7;
    int recu(int i, int g1, int g2, vector<int>& nums,vector<vector<vector<int>>>& dp) {
        int n = nums.size();
        // base case
        if (i == n) {
            if (g1 == g2 && g1 != 0 && g2 != 0)
                return 1;

            // agar last me phoch gye pr condition nhi satisfy hua to 0
            return 0;
        }

        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        int ans = 0;

        ans = (ans + recu(i + 1, g1, g2, nums , dp)) % mod;
        ans = (ans + recu(i + 1, gcd(g1, nums[i]), g2, nums , dp)) % mod;

        ans = (ans + recu(i + 1, g1, gcd(g2, nums[i]), nums , dp)) % mod;

        return dp[i][g1][g2] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(201, vector<int>(201, -1)));

        return recu(0, 0, 0, nums , dp);
    }
};