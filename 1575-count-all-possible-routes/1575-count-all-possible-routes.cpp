class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][201];

    int solve(int i, int f, vector<int>& locations, int finish) {
        if (dp[i][f] != -1)
            return dp[i][f];

        int ans = (i == finish) ? 1 : 0;

        for (int j = 0; j < locations.size(); j++) {
            if (i == j)
                continue;

            int cost = abs(locations[i] - locations[j]);

            if (cost <= f) {
                ans = (ans + solve(j, f - cost, locations, finish)) % mod;
            }
        }

        return dp[i][f] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return solve(start, fuel, locations, finish);
    }
};