class Solution {
public:

    double dp[101][101];

    double solve(int start, int k, vector<double>& prefix, int n) {

        if (k == 1) {
            return (prefix[n] - prefix[start]) / (n - start);
        }

        if (dp[start][k] != -1) {
            return dp[start][k];
        }

        double ans = 0;

        for (int end = start; end < n - 1; end++) {

            double sum = prefix[end + 1] - prefix[start];
            double average = sum / (end - start + 1);

            double remaining = solve(end + 1, k - 1, prefix, n);

            ans = max(ans, average + remaining);
        }

        return dp[start][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {

        int n = nums.size();

        vector<double> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;
            }
        }

        return solve(0, k, prefix, n);
    }
};