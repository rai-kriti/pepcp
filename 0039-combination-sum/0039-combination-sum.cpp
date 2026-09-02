class Solution {
public:
    void solve(vector<int>& candidates, int idx, int target,
               vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Since array is sorted, all further elements
            // will also be greater than target
            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            // i, not i+1 → same element can be reused
            solve(candidates, i, target - candidates[i], temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        solve(candidates, 0, target, temp, ans);

        return ans;
    }
};