class Solution {
public:
    map<vector<int>, int> dp;

    int solve(vector<int>& price,
              vector<vector<int>>& special,
              vector<int>& needs) {

        if (dp.count(needs))
            return dp[needs];

        // Option 1: buy everything normally
        int ans = 0;

        for (int i = 0; i < needs.size(); i++)
            ans += needs[i] * price[i];

        // Option 2: use any special offer
        for (auto& offer : special) {

            bool possible = true;
            vector<int> remaining = needs;

            for (int i = 0; i < needs.size(); i++) {

                if (offer[i] > needs[i]) {
                    possible = false;
                    break;
                }

                remaining[i] -= offer[i];
            }

            if (possible) {
                ans = min(ans,
                          offer.back() +
                          solve(price, special, remaining));
            }
        }

        return dp[needs] = ans;
    }

    int shoppingOffers(vector<int>& price,
                       vector<vector<int>>& special,
                       vector<int>& needs) {

        return solve(price, special, needs);
    }
};