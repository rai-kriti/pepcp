class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<vector<int>>& piles, int ind, int k) {
        if (k == 0) return 0;

        if (ind == piles.size()) {
            return -1e9;
        }

        if (dp[ind][k] != -1)
            return dp[ind][k];

        int ans = f(piles, ind + 1, k);

        int sum = 0;

        for (int i = 0; i < min(k, (int)piles[ind].size()); i++) {
            sum += piles[ind][i];
            ans = max(ans, sum + f(piles, ind + 1, k - i - 1));
        }

        return dp[ind][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        dp.assign(n, vector<int>(k + 1, -1));
        return f(piles, 0, k);
    }
};