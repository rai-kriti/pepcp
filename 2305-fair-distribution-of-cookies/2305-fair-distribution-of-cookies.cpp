class Solution {
    int minUnfairness = INT_MAX;

    void solve(int index, vector<int>& cookies, vector<int>& children, int k) {
        // Base case: saari cookies distribute ho gayi
        if (index == cookies.size()) {
            int currentMax = 0;
            for (int sum : children) {
                currentMax = max(currentMax, sum);
            }
            minUnfairness = min(minUnfairness, currentMax);
            return;
        }

        for (int j = 0; j < k; j++) {
            children[j] += cookies[index];
            
            // PRUNING 1: Agar ek bacche ka sum already current answer se bada ho gaya, 
            // toh aage explore karne ka koi fayda nahi. (Ye bahut time bachaega)
            if (children[j] < minUnfairness) {
                solve(index + 1, cookies, children, k);
            }
            
            // Backtrack
            children[j] -= cookies[index];

            // PRUNING 2: Agar kisi bacche ki basket khali hai (0), toh use skip karne ka
            // matlab nahi kyunki baaki khali baskets ke liye bhi same hi result aayega.
            if (children[j] == 0) {
                break;
            }
        }
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        solve(0, cookies, children, k);
        return minUnfairness;
    }
};