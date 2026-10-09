class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int mod = 1e9+7;
        vector<vector<int>> dp( n , vector<int>(fuel+1 , 0));
        //dp[i][f] i par khade hokar, f fuel ke saath finish tak kitne ways hain
        for(int f =0 ; f<= fuel ; f++){
            dp[finish][f] = 1;

            for(int i=0 ; i<n ; i++){
                for(int j=0; j<n ; j++){
                    if(i==j) continue;

                    int cost = abs(locations[i] - locations[j]);

                    if(cost <= f)
                        dp[i][f] = (dp[i][f] +  dp[j][f -  cost]) % mod;
                }
            }
        }

        return dp[start][fuel];
    }
};