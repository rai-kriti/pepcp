class Solution {
public:

    int maxCompatibilitySum(vector<vector<int>>& students,
                            vector<vector<int>>& mentors) {

        int m = students.size();

        // score[i][j] = compatibility of student i with mentor j
        vector<vector<int>> score(m, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {

                for (int k = 0; k < students[i].size(); k++) {
                    if (students[i][k] == mentors[j][k]) {
                        score[i][j]++;
                    }
                }
            }
        }

        // dp[mask] = maximum score after using mentors in mask
        vector<int> dp(1 << m, 0);

        for (int mask = 0; mask < (1 << m); mask++) {

            // Number of students already assigned
            int student = __builtin_popcount(mask);

            // All students assigned
            if (student == m)
                continue;

            // Try every unused mentor
            for (int mentor = 0; mentor < m; mentor++) {

                // mentor is already used
                if (mask & (1 << mentor))
                    continue;

                int newMask = mask | (1 << mentor);

                dp[newMask] = max(
                    dp[newMask],
                    dp[mask] + score[student][mentor]
                );
            }
        }

        return dp[(1 << m) - 1];
    }
};