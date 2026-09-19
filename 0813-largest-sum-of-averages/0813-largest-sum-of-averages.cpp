class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {

        int n = nums.size();

        vector<double> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<double> dp(n + 1, 0);

        // 1 group
        for (int i = 1; i <= n; i++) {
            dp[i] = prefix[i] / i;
        }

        // 2 to k groups
        for (int groups = 2; groups <= k; groups++) {

            vector<double> next(n + 1, 0);

            for (int i = groups; i <= n; i++) {

                for (int j = groups - 1; j < i; j++) {

                    double average = (prefix[i] - prefix[j]) / (i - j);

                    next[i] = max(next[i], dp[j] + average);
                }
            }

            dp = next;
        }

        return dp[n];
    }
};