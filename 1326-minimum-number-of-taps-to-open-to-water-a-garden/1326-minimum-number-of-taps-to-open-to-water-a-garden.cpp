class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<int> maxReach(n + 1, 0);

        // Convert taps into intervals
        for (int i = 0; i <= n; i++) {

            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);

            maxReach[left] = max(maxReach[left], right);
        }

        int taps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i <= n; i++) {

            // Best interval we can choose from
            // all intervals starting <= i
            farthest = max(farthest, maxReach[i]);

            // We have reached the end
            if (currentEnd >= n)
                return taps;

            // Need to open another tap
            if (i == currentEnd) {

                // Cannot extend coverage
                if (farthest <= currentEnd)
                    return -1;

                taps++;
                currentEnd = farthest;
            }
        }

        return -1;
    }
};