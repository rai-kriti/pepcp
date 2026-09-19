#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

   
        static int dp[1500][1001];
      
        fill(&dp[0][0], &dp[0][0] + 1500 * 1001, 0);

        int max_len = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500;
                
                // Agar j par pehle se sequence tha toh +1 karo, varna new 2-length sequence
                dp[i][diff] = (dp[j][diff] > 0) ? dp[j][diff] + 1 : 2;
                
                max_len = max(max_len, dp[i][diff]);
            }
        }

        return max_len;
    }
};