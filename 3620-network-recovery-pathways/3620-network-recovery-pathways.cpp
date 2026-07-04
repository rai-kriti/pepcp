class Solution {
public:

    bool isPossible(int mid,vector<vector<pair<int,int>>>& adj,long long k){
       int n = adj.size();
        vector<long long> minDist(n, -1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        pq.push({0, 0});
        minDist[0] = 0;

        while(!pq.empty()) {
            long long dist = pq.top().first;
            int nd = pq.top().second;
            pq.pop();

            if (dist > minDist[nd]) continue;
            if (nd == n - 1) return true;

            for(auto& edge : adj[nd]) {
                int neigh = edge.first;
                int wt = edge.second;
                if(wt >= mid && dist + wt <= k) {
                    if (minDist[neigh] == -1 || dist + wt < minDist[neigh]) {
                        minDist[neigh] = dist + wt;
                        pq.push({minDist[neigh], neigh});
                    }
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
       int n = online.size();
        
        vector<vector<pair<int,int>>> adj(n);
        // vector<vector<pair<int,int>>> adj(maxElem + 1);
            int maxWt = 0;

        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            maxWt = max(maxWt,wt);
            if(online[u] && online[v]){
                adj[u].push_back({v,wt});
            }
            // adj[v].push_back({u,wt});
        }

        int lo = 0, hi = maxWt ;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossible(mid,adj,k)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return ans;
    }
};