class Solution {
public:
    vector<vector<string>> result;
    int n;

    void solve(int row, int col, int diag1, int diag2,
               vector<string>& board) {

        if (row == n) {
            result.push_back(board);
            return;
        }

        int mask = (1 << n) - 1;
        int remaining = mask & ~(col | diag1 | diag2);

        while (remaining) {

            // rightmost set bit
            int bit = remaining & -remaining;

            remaining -= bit;

            int c = __builtin_ctz(bit);

            board[row][c] = 'Q';

            solve(
                row + 1,
                col | bit,
                (diag1 | bit) << 1,
                (diag2 | bit) >> 1,
                board
            );

            board[row][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        this->n = n;

        vector<string> board(n, string(n, '.'));

        solve(0, 0, 0, 0, board);

        return result;
    }
};