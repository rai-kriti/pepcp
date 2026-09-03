class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, int k, int target, vector<int>& temp) {

        if (k == 0) {
            if (target == 0)
                ans.push_back(temp);
            return;
        }

        // Minimum possible sum
        int minSum = k * (2 * start + k - 1) / 2;

        // Maximum possible sum
        int maxSum = k * (19 - k) / 2;

        if (target < minSum || target > maxSum)
            return;

        for (int i = start; i <= 9; i++) {

            if (i > target)
                break;

            temp.push_back(i);

            solve(i + 1, k - 1, target - i, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(1, k, n, temp);
        return ans;
    }
};