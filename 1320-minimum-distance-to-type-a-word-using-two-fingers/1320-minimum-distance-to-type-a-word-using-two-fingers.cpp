
class Solution {
public:
    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0;

        return abs(a / 6 - b / 6) +
               abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        int dp[301][27] = {};

        for (int i = n - 1; i >= 1; i--) {
            int curr = word[i] - 'A';
            int prev = word[i - 1] - 'A';

            for (int other = 0; other <= 26; other++) {
                int cost1 = dist(prev, curr)
                          + dp[i + 1][other];

                int cost2 = dist(other, curr)
                          + dp[i + 1][prev];

                dp[i][other] = min(cost1, cost2);
            }
        }

        return dp[1][26];
    }
};
