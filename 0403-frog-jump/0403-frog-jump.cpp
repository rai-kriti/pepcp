
class Solution {
public:
    unordered_map<int, int> mp;
    vector<vector<int>> memo;

    bool f(vector<int>& stones, int posIndex, int jump, int n) {
        if (posIndex == n - 1)
            return true;

        if (memo[posIndex][jump] != -1)
            return memo[posIndex][jump];

        int currPos = stones[posIndex];

        // Jump k - 1
        if (jump > 1 && mp.count(currPos + jump - 1)) {
            int nextIndex = mp[currPos + jump - 1];

            if (f(stones, nextIndex, jump - 1, n))
                return memo[posIndex][jump] = 1;
        }

        // Jump k
        if (mp.count(currPos + jump)) {
            int nextIndex = mp[currPos + jump];

            if (f(stones, nextIndex, jump, n))
                return memo[posIndex][jump] = 1;
        }

        // Jump k + 1
        if (mp.count(currPos + jump + 1)) {
            int nextIndex = mp[currPos + jump + 1];

            if (f(stones, nextIndex, jump + 1, n))
                return memo[posIndex][jump] = 1;
        }

        return memo[posIndex][jump] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (stones[1] != 1)
            return false;

        mp.clear();
        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;

        memo.assign(n, vector<int>(n + 1, -1));

        return f(stones, 1, 1, n);
    }
};
