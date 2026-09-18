class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int r = 1; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int left = (c > 0) ? matrix[r - 1][c - 1] : INT_MAX;
                int mid = matrix[r - 1][c];
                int right = (c < n - 1) ? matrix[r - 1][c + 1] : INT_MAX;
                
                matrix[r][c] += min({left, mid, right});
            }
        }
        
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};