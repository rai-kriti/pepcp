#include <cmath>

class Solution {
private:
    bool isSquare(int n) {
        int r = round(sqrt(n));
        return r * r == n;
    }

public:
    int numSquares(int n) {
        // Case 1: n is a perfect square
        if (isSquare(n)) return 1;

        // Case 4: n = 4^k * (8m + 7)
        int temp = n;
        while (temp % 4 == 0) {
            temp /= 4;
        }
        if (temp % 8 == 7) return 4;

        // Case 2: n = a^2 + b^2
        for (int i = 1; i * i <= n; ++i) {
            if (isSquare(n - i * i)) return 2;
        }

        // Case 3: By elimination
        return 3;
    }
};