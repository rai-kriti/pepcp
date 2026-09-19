#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        
        // Base case: Day 0
        int hold = -prices[0];
        int free = 0;
        
        for (int i = 1; i < n; ++i) {
            int prev_hold = hold;
            
            // Hold state: keep holding previous stock, or buy today from 'free' cash
            hold = max(hold, free - prices[i]);
            
            // Free state: stay free, or sell held stock today and pay fee
            free = max(free, prev_hold + prices[i] - fee);
        }
        
        return free; // Profit at the end when holding no stock
    }
};