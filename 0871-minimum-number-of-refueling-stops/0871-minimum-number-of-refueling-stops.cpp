class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size(), ans = 0, furthest = startFuel;
        priority_queue<int> pq;

        for (int i = 0; i < n;) {
            // need to at least get to next station
            while (!pq.empty() && furthest < stations[i][0]) {
                furthest += pq.top(); pq.pop();
                ans++;
            }

            // add all valid canidates
            while (i < n && furthest >= stations[i][0]) {
                pq.push(stations[i][1]); 
                i++;
            }

            // no valid canidates => can't reach
            if (pq.empty())
                return -1;
        }

        while (!pq.empty() && furthest < target) {
            furthest += pq.top(); pq.pop();
            ans++;
        }

        return furthest >= target ? ans : -1;
    }
};