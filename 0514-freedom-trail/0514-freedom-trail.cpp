class Solution {
public:

    int count_steps(int current, int target, int n) {
        int dist = abs(current - target);

        return min(dist, n - dist);
    }

    int findRotateSteps(string ring, string key) {

        int n = ring.length();
        int m = key.length();

        vector<vector<int>> dp(n, vector<int>(m + 1, 0));

        for (int key_index = m - 1; key_index >= 0; key_index--) {

            for (int ring_index = 0; ring_index < n; ring_index++) {

                dp[ring_index][key_index] = INT_MAX;

                for (int i = 0; i < n; i++) {

                    if (ring[i] == key[key_index]) {

                        int rotate = count_steps(ring_index, i, n);

                        int total = rotate + 1 + dp[i][key_index + 1];

                        dp[ring_index][key_index] =
                            min(dp[ring_index][key_index], total);
                    }
                }
            }
        }

        return dp[0][0];
    }
};