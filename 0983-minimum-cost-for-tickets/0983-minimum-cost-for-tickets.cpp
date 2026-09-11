#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        // Queues store pairs of: {day, total_cost_if_pass_bought_on_that_day}
        std::queue<std::pair<int, int>> last7;
        std::queue<std::pair<int, int>> last30;
        int current_cost = 0;

        for (int day : days) {
            // Evict passes that expired before the current day
            while (!last7.empty() && last7.front().first + 7 <= day) {
                last7.pop();
            }
            while (!last30.empty() && last30.front().first + 30 <= day) {
                last30.pop();
            }

            // Buying a 7-day or 30-day pass starting today extends from current_cost
            last7.push({day, current_cost + costs[1]});
            last30.push({day, current_cost + costs[2]});

            // The minimum cost to cover up to this day is the cheapest of:
            // 1. Extending the previous day with a 1-day pass
            // 2. The cheapest active 7-day pass (earliest valid pass in the queue)
            // 3. The cheapest active 30-day pass (earliest valid pass in the queue)
            current_cost = std::min({
                current_cost + costs[0],
                last7.front().second,
                last30.front().second
            });
        }

        return current_cost;
    }
};