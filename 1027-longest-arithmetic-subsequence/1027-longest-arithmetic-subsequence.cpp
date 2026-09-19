class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(1001, 0));

        int ans = 2;

        for (int i = 1; i < n; i++) {

            for (int j = 0; j < i; j++) {

                int diff = nums[i] - nums[j] + 500;

                dp[i][diff] = dp[j][diff] + 1;

                ans = max(ans, dp[i][diff] + 1);
            }
        }

        return ans;
    }
};