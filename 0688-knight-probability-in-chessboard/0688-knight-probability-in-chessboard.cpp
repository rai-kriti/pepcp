#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    double memo[25][25][101];

    // 8 possible knight moves
    int moves[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2},  {1, 2},  {2, -1},  {2, 1}
    };

    double solve(int n, int k, int r, int c) {
        // Out of bounds -> off board
        if (r < 0 || r >= n || c < 0 || c >= n) return 0.0;

        // All moves completed -> safely on board
        if (k == 0) return 1.0;

        // Memoization check
        if (memo[r][c][k] > 0.0) return memo[r][c][k];

        double prob = 0.0;
        for (auto& m : moves) {
            prob += solve(n, k - 1, r + m[0], c + m[1]) / 8.0;
        }

        return memo[r][c][k] = prob;
    }

public:
    double knightProbability(int n, int k, int row, int column) {
        fill(&memo[0][0][0], &memo[0][0][0] + 25 * 25 * 101, 0.0);
        return solve(n, k, row, column);
    }
};