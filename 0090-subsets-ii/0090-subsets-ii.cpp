class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int mask = 0; mask < (1 << n); mask++) {
            bool valid = true;

            for (int j = 1; j < n; j++) {
                if ((mask & (1 << j)) &&
                    nums[j] == nums[j - 1] &&
                    !(mask & (1 << (j - 1)))) {
                    valid = false;
                    break;
                }
            }

            if (!valid) continue;

            ans.push_back({});

            for (int j = 0; j < n; j++)
                if (mask & (1 << j))
                    ans.back().push_back(nums[j]);
        }

        return ans;
    }
};