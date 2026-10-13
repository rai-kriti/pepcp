
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int sum = 0, ans = 0;

        for (int x : nums) {
            sum += x;
            ans += freq[sum - goal];
            freq[sum]++;
        }

        return ans;
    }
};
