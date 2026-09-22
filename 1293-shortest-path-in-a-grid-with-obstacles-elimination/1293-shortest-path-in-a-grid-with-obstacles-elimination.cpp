class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        queue<tuple<int, int, int>> q;

        // row, col, remaining k
        q.push({0, 0, k});

        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(k + 1, false))
        );

        visited[0][0][k] = true;

        int steps = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, rem] = q.front();
                q.pop();

                if (r == m - 1 && c == n - 1)
                    return steps;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    int newRem = rem - grid[nr][nc];

                    if (newRem < 0)
                        continue;

                    if (visited[nr][nc][newRem])
                        continue;

                    visited[nr][nc][newRem] = true;

                    q.push({nr, nc, newRem});
                }
            }

            steps++;
        }

        return -1;
    }
};