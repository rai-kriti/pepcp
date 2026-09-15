class Solution {
public:

    int countZeros(string s) {
        int cnt = 0;

        for(char ch : s) {
            if(ch == '0') {
                cnt++;
            }
        }

        return cnt;
    }

    int countOnes(string s) {
        int cnt = 0;

        for(char ch : s) {
            if(ch == '1') {
                cnt++;
            }
        }

        return cnt;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Process every string one by one
        for(string s : strs) {

            int zeros = countZeros(s);
            int ones = countOnes(s);

            // Go backwards because this is 0/1 Knapsack
            for(int i = m; i >= zeros; i--) {

                for(int j = n; j >= ones; j--) {

                    dp[i][j] = max(
                        dp[i][j],
                        dp[i - zeros][j - ones] + 1
                    );
                }
            }
        }

        return dp[m][n];
    }
};