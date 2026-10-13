
class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int limit = n / 4;
        int freq[4] = {};

        for (char c : s) {
            if (c == 'Q') freq[0]++;
            else if (c == 'W') freq[1]++;
            else if (c == 'E') freq[2]++;
            else freq[3]++;
        }

        int left = 0, ans = n;

        for (int right = 0; right < n; right++) {
            if (s[right] == 'Q') freq[0]--;
            else if (s[right] == 'W') freq[1]--;
            else if (s[right] == 'E') freq[2]--;
            else freq[3]--;

            while (freq[0] <= limit &&
                   freq[1] <= limit &&
                   freq[2] <= limit &&
                   freq[3] <= limit) {
                ans = min(ans, right - left + 1);

                if (s[left] == 'Q') freq[0]++;
                else if (s[left] == 'W') freq[1]++;
                else if (s[left] == 'E') freq[2]++;
                else freq[3]++;

                left++;
            }
        }

        return ans;
    }
};
