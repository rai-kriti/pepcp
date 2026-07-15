class Solution {
public:

    int dp[11][2][2][2][1<<10];

    int helper(string &s, int i, bool tight, bool lz, bool repeat, int mask){
        //base case
        if(i == s.size()) return repeat;

        if(dp[i][tight][lz][repeat][mask] != -1) return dp[i][tight][lz][repeat][mask];

        int lb = 0;
        int ub = tight ? s[i]-'0' : 9;

        int ways = 0;

        for(int dig = lb; dig <= ub; dig++){

            if(dig==0 && lz) ways += helper(s,i+1,tight&&(dig==ub),true,repeat,mask);

            else{

                bool new_repeat = repeat;
                if((mask&(1<<dig))) new_repeat = true;

                ways += helper(s,i+1,tight&&(dig==ub),false,new_repeat,(mask|(1<<dig)));
            }
        }
        return dp[i][tight][lz][repeat][mask] = ways;
    }
    int numDupDigitsAtMostN(int n) {

        //using mask to track repeated digit
        
        string s = to_string(n);

        memset(dp,-1,sizeof(dp));

        return helper(s,0,true,true,false,0);
    }
};