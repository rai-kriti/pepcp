class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        int n = happiness.size();
        long long ans = 0;
        int j = n - 1;

        for (int i = 0; i < k; i++) {
            ans += max(0, happiness[j] - i);
            j--;
        }

        return ans;
    }
};