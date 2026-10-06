class Solution {
    vector<vector<int>> dp;

    int solve(int index, int remaining, vector<int>& cost) {
        if (remaining == 0) return 0;
        if (index < 0) return -1;

        int& best = dp[index][remaining];
        if (best != -2) return best;

        best = solve(index - 1, remaining, cost);

        if (remaining >= cost[index]) {
            int take = solve(index, remaining - cost[index], cost);

            if (take != -1) {
                best = max(best, 1 + take);
            }
        }

        return best;
    }

public:
    string largestNumber(vector<int>& cost, int target) {
        dp.assign(9, vector<int>(target + 1, -2));

        if (solve(8, target, cost) == -1) return "0";

        string answer;
        int remaining = target;

        for (int index = 8; index >= 0; index--) {
            while (remaining >= cost[index] && solve(index, remaining, cost) ==  1 + solve(index, remaining - cost[index], cost)) {
                answer.push_back(char('1' + index));
                remaining -= cost[index];
            }
        }

        return answer;
    }
};