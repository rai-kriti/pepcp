class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& cost, int target) {

        if (target == 0)
            return 0;

        // -2 means not calculated yet
        if (dp[target] != -2)
            return dp[target];

        int best = -1;  // -1 means impossible

        for (int d = 1; d <= 9; d++) {

            if (cost[d - 1] <= target) {

                int next = solve(cost, target - cost[d - 1]);

                if (next != -1) {
                    best = max(best, 1 + next);
                }
            }
        }

        return dp[target] = best;
    }

    string largestNumber(vector<int>& cost, int target) {

        // -2 = not calculated
        dp.resize(target + 1, -2);

        int length = solve(cost, target);

        if (length == -1)
            return "0";

        string ans = "";

        while (length > 0) {

            for (int d = 9; d >= 1; d--) {

                if (cost[d - 1] <= target &&
                    solve(cost, target - cost[d - 1]) == length - 1) {

                    ans += to_string(d);

                    target -= cost[d - 1];
                    length--;

                    break;
                }
            }
        }

        return ans;
    }
};