class Solution {
public:
    int numDecodings(string s) {

        const long long MOD = 1000000007;
        int n = s.size();

        vector<long long> dp(n + 1, 0);

        // Empty string
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            
            // Take one character

            char ch = s[i - 1];

            if (ch == '*') {

                // '*' can be 1 to 9
                dp[i] += 9 * dp[i - 1];

            }
            else if (ch != '0') {

                // 1 to 9
                dp[i] += dp[i - 1];
            }

            // Take two characters

            if (i >= 2) {

                char first = s[i - 2];
                char second = s[i - 1];

                // **
                if (first == '*' && second == '*') {

                    // 11-19 -> 9
                    // 21-26 -> 6
                    // total = 15

                    dp[i] += 15 * dp[i - 2];
                }

                // *digit
                else if (first == '*') {

                    if (second >= '0' && second <= '6') {

                        // 10-16 or 20-26
                        dp[i] += 2 * dp[i - 2];

                    }
                    else {

                        // 17-19
                        dp[i] += dp[i - 2];
                    }
                }

                // digit*
                else if (second == '*') {

                    if (first == '1') {

                        // 11-19
                        dp[i] += 9 * dp[i - 2];

                    }
                    else if (first == '2') {

                        // 21-26
                        dp[i] += 6 * dp[i - 2];
                    }
                }

                // digit digit
                else {

                    int num = (first - '0') * 10
                            + (second - '0');

                    if (num >= 10 && num <= 26) {

                        dp[i] += dp[i - 2];
                    }
                }
            }

            dp[i] %= MOD;
        }

        return dp[n];
    }
};