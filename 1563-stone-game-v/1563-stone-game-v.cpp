class Solution {
public:

    int solve(int l, int r, vector<int>& a,
              vector<int>& prefix,
              vector<vector<int>>& dp) {

        if(l == r) {
            return 0;
        }

        if(dp[l][r] != -1) {
            return dp[l][r];
        }

        int ans = 0;

        for(int k = l; k < r; k++) {
            //find the sum
            int left = prefix[k+1] - prefix[l];
            int right = prefix[r+1] - prefix[k+1];

           // If left sum is smaller, Bob discards the right partition.
// Alice keeps the left partition, earns its sum,
// and continues playing on the left interval.
if(left < right) {
    ans = max(ans, left + solve(l, k, a, prefix, dp));
}

// If right sum is smaller, Bob discards the left partition.
// Alice keeps the right partition, earns its sum,
// and continues playing on the right interval.
else if(left > right) {
    ans = max(ans, right + solve(k+1, r, a, prefix, dp));
}

// If both sums are equal, Alice gets to choose which
// partition to keep. She chooses the one giving maximum
// future score and adds the common partition sum.
else {
    ans = max(ans, left + max(
        solve(l, k, a, prefix, dp),
        solve(k+1, r, a, prefix, dp)
    ));
}
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> prefix(n+1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n-1, stoneValue, prefix, dp);
    }
};