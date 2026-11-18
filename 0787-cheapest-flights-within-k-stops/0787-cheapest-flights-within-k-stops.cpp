
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        int kcount = 0;

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});

        while(!q.empty() && kcount <= k) {
            int lvl = q.size();

            while(lvl--) {
                int u = q.front().first;
                int cost = q.front().second;
                q.pop();

                for(auto &ed : adj[u]) {
                    int v = ed.first;
                    int wt = ed.second;

                    if(cost + wt < dist[v]) {
                        dist[v] = cost + wt;
                        q.push({v, dist[v]});
                    }
                }
            }

            kcount++;
        }

        if(dist[dst] == INT_MAX) {
            return -1;
        }

        return dist[dst];
    }
};
