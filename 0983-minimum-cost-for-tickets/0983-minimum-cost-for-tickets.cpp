#include <vector>
#include <algorithm>

class Solution {
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        // Fast I/O
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = days.size();
        std::vector<int> dp(n + 1, 0);

        int j7 = n - 1;
        int j30 = n - 1;

        // Backward DP with two monotonic pointers
        for (int i = n - 1; i >= 0; --i) {
            // 1-day pass
            int c1 = costs[0] + dp[i + 1];

            // 7-day pass: find first day not covered by days[i] + 6
            while (j7 >= 0 && days[j7] > days[i] + 6) {
                --j7;
            }
            int c7 = costs[1] + dp[j7 + 1];

            // 30-day pass: find first day not covered by days[i] + 29
            while (j30 >= 0 && days[j30] > days[i] + 29) {
                --j30;
            }
            int c30 = costs[2] + dp[j30 + 1];

            dp[i] = std::min({c1, c7, c30});
        }

        return dp[0];
    }
};