class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<vector<int>>& pref, int ind, int k) {
        if (k == 0)
            return 0;

        if (ind == pref.size())
            return -1000000000;

        if (dp[ind][k] != -1)
            return dp[ind][k];

        // Take 0 coins from current pile
        int ans = f(pref, ind + 1, k);

        int limit = min(k, (int)pref[ind].size() - 1);

        // Try taking 1,2,3... coins
        for (int take = 1; take <= limit; take++) {
            ans = max(ans,
                      pref[ind][take] + f(pref, ind + 1, k - take));
        }

        return dp[ind][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        // Prefix sums
        vector<vector<int>> pref(n);

        for (int i = 0; i < n; i++) {
            pref[i].push_back(0);

            for (int coin : piles[i]) {
                pref[i].push_back(pref[i].back() + coin);
            }
        }

        dp.assign(n, vector<int>(k + 1, -1));

        return f(pref, 0, k);
    }
};