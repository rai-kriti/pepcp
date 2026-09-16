class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> mx(n);
        vector<long long> mn(n);

        mx[0] = mn[0] = grid[0][0];

        // First row
        for (int j = 1; j < n; j++) {
            mx[j] = mn[j] = mx[j - 1] * grid[0][j];
        }

        for (int i = 1; i < m; i++) {

            // First column
            mx[0] = mn[0] = mx[0] * grid[i][0];

            for (int j = 1; j < n; j++) {

                long long x = grid[i][j];

                long long topMax = mx[j];
                long long topMin = mn[j];

                long long leftMax = mx[j - 1];
                long long leftMin = mn[j - 1];

                long long a = topMax * x;
                long long b = topMin * x;
                long long c = leftMax * x;
                long long d = leftMin * x;

                mx[j] = max({a, b, c, d});
                mn[j] = min({a, b, c, d});
            }
        }

        if (mx[n - 1] < 0)
            return -1;

        return mx[n - 1] % 1000000007;
    }
};