class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& temp, int mask) {
        int n = nums.size();

        if (mask == (1 << n) - 1) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {

            // Check if nums[i] is already used
            if (mask & (1 << i))
                continue;

            temp.push_back(nums[i]);

            // Mark i as used
            solve(nums, temp, mask | (1 << i));

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;

        solve(nums, temp, 0);

        return ans;
    }
};