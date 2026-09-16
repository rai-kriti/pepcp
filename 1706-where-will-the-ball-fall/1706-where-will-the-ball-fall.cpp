class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans(n, -1);

        for(int ball = 0; ball < n; ball++) {
            int row = 0;
            int col = ball;
            bool stuck = false;

            while(row < m) {

                if(grid[row][col] == 1) {

                    if(col == n - 1 || grid[row][col + 1] == -1) {
                        stuck = true;
                        break;
                    }

                    col++;
                }
                else {

                    if(col == 0 || grid[row][col - 1] == 1) {
                        stuck = true;
                        break;
                    }

                    col--;
                }

                row++;
            }

            if(!stuck)
                ans[ball] = col;
        }

        return ans;
    }
};