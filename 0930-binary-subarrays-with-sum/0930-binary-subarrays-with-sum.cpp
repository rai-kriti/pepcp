
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        if (goal == 0) {
            int zeros = 0, ans = 0;

            for (int x : nums) {
                if (x == 0) {
                    zeros++;
                    ans += zeros;
                } else {
                    zeros = 0;
                }
            }

            return ans;
        }
        
        int left = 0, count = 0, ans = 0, sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (left <= right && sum > goal) {
                sum -= nums[left];
                left++;
                count = 0;
            }

            while (left <= right && sum == goal && nums[left] == 0) {
                count++;
                left++;
            }

            if (sum == goal) {
                ans += count + 1;
            }
        }

        return ans;
    }
};
