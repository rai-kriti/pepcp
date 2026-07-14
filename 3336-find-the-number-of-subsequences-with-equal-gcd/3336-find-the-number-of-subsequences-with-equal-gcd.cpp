class Solution {
public:
    int mod = 1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
         int maxi = *max_element(nums.begin() , nums.end());
         vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(maxi+1, vector<int>(maxi+1, 0))
        );

        //base case bhar lo
        for(int i=1 ; i<= maxi ; i++){
            dp[n][i][i] = 1;
        }
        
        for(int i = n-1 ; i>=0 ; i--){
            for(int g1 = 0 ; g1<= maxi ; g1++){
                for(int g2 =0 ; g2 <= maxi ; g2++){
                    long long ans =0;
                    
                    ans = (ans+ dp[i+1][g1][g2])%mod;
                    ans = (ans+ dp[i+1][gcd(g1 , nums[i])][g2]) %mod;
                    ans = ( ans + dp[i+1][g1][gcd(g2 , nums[i])]) %mod;

                    dp[i][g1][g2] =  ans;
                }
            }
        }

        return dp[0][0][0];

    }
};