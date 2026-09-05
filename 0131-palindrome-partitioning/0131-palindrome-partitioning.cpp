class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(int start, string& s, vector<vector<bool>>& pal) {
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            if (!pal[start][end])
                continue;

            path.push_back(s.substr(start, end - start + 1));

            dfs(end + 1, s, pal);

            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Precompute palindrome substrings
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        dfs(0, s, pal);

        return ans;
    }
};