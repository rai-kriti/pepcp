class Solution {
public:
    void backtrack(int n, int k, int start,
                   vector<int>& temp,
                   vector<vector<int>>& ans) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        int remaining = k - temp.size();

        for (int i = start; i <= n - remaining + 1; i++) {

            temp.push_back(i);

            backtrack(n, k, i + 1, temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        backtrack(n, k, 1, temp, ans);

        return ans;
    }
};