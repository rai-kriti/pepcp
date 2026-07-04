class Solution {
public:

    void shortestPathInDAG(int src,
                           vector<vector<pair<int,int>>> &graph,
                           vector<int> &indegree,
                           vector<long long> &dist) {

        int n = graph.size();

        queue<int> q;
        vector<int> indeg = indegree;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        dist.assign(n, LLONG_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] != LLONG_MAX) {
                for (auto &it : graph[u]) {
                    int v = it.first;
                    int w = it.second;

                    dist[v] = min(dist[v], dist[u] + 1LL * w);
                }
            }

            for (auto &it : graph[u]) {
                int v = it.first;

                indeg[v]--;

                if (indeg[v] == 0)
                    q.push(v);
            }
        }
    }

    bool check(long long mid,
               vector<vector<pair<int,int>>> &graph,
               vector<int> &indegree,
               vector<bool> &online,
               long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> newGraph(n);
        vector<int> newIndegree(n, 0);

        for (int u = 0; u < n; u++) {

            if (u != 0 && u != n - 1 && !online[u])
                continue;

            for (auto &it : graph[u]) {

                int v = it.first;
                int w = it.second;

                if (w < mid)
                    continue;

                if (v != n - 1 && !online[v])
                    continue;

                newGraph[u].push_back({v, w});
                newIndegree[v]++;
            }
        }

        vector<long long> dist;

        shortestPathInDAG(0, newGraph, newIndegree, dist);

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n, 0);

        vector<int> values;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({v, w});
            indegree[v]++;

            values.push_back(w);
        }

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int low = 0;
        int high = values.size() - 1;

        int ans = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (check(values[mid], graph, indegree, online, k)) {
                ans = values[mid];
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};