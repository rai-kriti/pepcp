class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod =  1e9+7;
        vector<long long> dp(5 , 1);
        for(int len =2 ; len <= n; len++){
            vector<long long> ndp(5);

            ndp[0] = (dp[1] + dp[2] + dp[4]) % mod;
            ndp[1] = (dp[0] + dp[2]) % mod;
            ndp[2] = (dp[1] + dp[3]) % mod;
            ndp[3] = dp[2];
            ndp[4] = (dp[2] + dp[3]) % mod;

            dp = ndp;
        }

        long long ans =0 ;
        for(int x : dp)( ans =  (ans+x)%mod);


        return ans;
    }
};