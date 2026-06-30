class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long> diff;

        // Difference marking
        for (auto &seg : segments) {
            diff[seg[0]] += seg[2];
            diff[seg[1]] -= seg[2];
        }

        vector<vector<long long>> ans;

        long long sum = 0;
        long long start = -1;

        for (auto &it : diff) {
            long long end = it.first;

            // Previous segment
            if (start != -1 && sum != 0) {
                ans.push_back({start, end, sum});
            }

            // Prefix sum update
            sum += it.second;

            // Next segment starts from current point
            start = end;
        }

        return ans;
    }
};