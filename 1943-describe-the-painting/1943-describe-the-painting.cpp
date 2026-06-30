class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& s) {

        int mx = 0;
        for (auto &seg : s)
            mx = max(mx, seg[1]);

        vector<long long> p(mx + 1, 0);

        for (int i = 0; i < s.size(); i++) {
            int l = s[i][0], r = s[i][1], c = s[i][2];
            p[l] += c;
            p[r] -= c;
        }

        for (int i = 1; i <= mx; i++)
            p[i] += p[i - 1];

        for (int i = 0; i < s.size(); i++) {
            int l = s[i][0];
            if (p[l] > 0)
                p[l] *= -1;
        }

        vector<vector<long long>> ans;

        for (int i = 0; i <= mx; i++) {
            if (p[i] != 0) {
                long long mag = abs(p[i]);
                int j = i + 1;

                while (j <= mx && p[j] > 0 && p[j] == mag)
                    j++;

                ans.push_back({(long long)i, (long long)j, mag});
                i = j - 1;
            }
        }

        return ans;
    }
};