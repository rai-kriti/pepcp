
class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int left = 0, maxFreq = 0, ans = 0;
        int n = s.length();

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
