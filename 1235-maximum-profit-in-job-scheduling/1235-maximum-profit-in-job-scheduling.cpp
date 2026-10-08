class Solution {
public:
    int findJob(vector<vector<int>>& jobs, int i) {
        int l = 0, r = i - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (jobs[mid][0] <= jobs[i][1]) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        vector<vector<int>> jobs;

        for (int i = 0; i < startTime.size(); i++)
            jobs.push_back({endTime[i], startTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());

        int n = jobs.size();
        vector<int> dp(n);

        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {

            int prev = findJob(jobs, i);

            // either take current or skip it
            if (prev != -1)
                dp[i] = max(dp[i - 1], jobs[i][2] + dp[prev]);
            else
                dp[i] = max(dp[i - 1], jobs[i][2]);
        }

        return dp[n - 1];
    }
};