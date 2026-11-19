
class Solution {
public:

    int dijkstra(vector<vector<pair<int,int>>>& adj, int n) {

        vector<int> dist(n, 1e9);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int d = p.first;
            int u = p.second;

            if (d > dist[u]) continue;

            for (auto edge : adj[u]) {

                int v = edge.first;
                int cost = edge.second;

                if (dist[v] > d + cost) {

                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[1];
    }

    int minimumCost(vector<int>& start, vector<int>& target,
                    vector<vector<int>>& specialRoads) {

        vector<vector<int>> points;

        points.push_back(start);
        points.push_back(target);

        for (auto road : specialRoads) {

            points.push_back({road[0], road[1]});
            points.push_back({road[2], road[3]});
        }

        int n = points.size();

        vector<vector<pair<int,int>>> adj(n);

        // Normal movement edges
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                int cost = abs(points[i][0] - points[j][0])
                         + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, cost});
            }
        }

        // Special road edges
        for (int i = 0; i < specialRoads.size(); i++) {

    int u = 2 + 2*i;
    int v = u + 1;

    adj[u].push_back({v, specialRoads[i][4]});
}

        return dijkstra(adj, n);
    }
};
