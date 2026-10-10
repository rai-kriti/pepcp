
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (stones[1] != 1)
            return false;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;

        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        dp[1][1] = true;

        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= n; k++) {
                if (!dp[i][k])
                    continue;

                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump <= 0)
                        continue;

                    int nextPos = stones[i] + jump;

                    if (mp.count(nextPos)) {
                        int j = mp[nextPos];
                        dp[j][jump] = true;
                    }
                }
            }
        }

        for (int k = 1; k <= n; k++) {
            if (dp[n - 1][k])
                return true;
        }

        return false;
    }
};
