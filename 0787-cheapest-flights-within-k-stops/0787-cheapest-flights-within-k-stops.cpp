class Solution {
public:
    struct Pair {
        int node;
        int cost;
        int stop;
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<Pair> q;
        q.push({src, 0, 0});

        while (!q.empty()) {

            Pair cur = q.front();
            q.pop();

            if (cur.stop > k) continue;

            for (auto &it : adj[cur.node]) {

                int nextNode = it.first;
                int newCost = cur.cost + it.second;

                if (newCost < dist[nextNode]) {
                    dist[nextNode] = newCost;
                    q.push({nextNode, newCost, cur.stop + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};