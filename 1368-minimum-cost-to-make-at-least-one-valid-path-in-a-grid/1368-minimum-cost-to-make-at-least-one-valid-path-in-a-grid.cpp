
class Solution {
public:
    int dx[5] = {0, 0, 0, 1, -1};
    int dy[5] = {0, 1, -1, 0, 0};

    bool isvalid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto p = dq.front();
            dq.pop_front();

            int x = p.first;
            int y = p.second;

            for (int d = 1; d <= 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (!isvalid(nx, ny, m, n)) {
                    continue;
                }

                int cost = 1;

                if (grid[x][y] == d) {
                    cost = 0;
                }

                if (dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0) {
                        dq.push_front({nx, ny});
                    }
                    else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
