#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        // 1. Fast letter count using constraint: ASCII letters are strictly > '9' (57)
        int letter_count = 0;
        for (unsigned char c : s) {
            letter_count += (c > '9');
        }

        // 2. Pre-allocate exact capacity (1 << letter_count == 2^letter_count)
        vector<string> result;
        result.reserve(1 << letter_count);
        result.push_back(s);

        // 3. Iterative doubling with bitwise XOR case toggle
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] > '9') { // It's an alphabetic character
                int sz = result.size();
                for (int j = 0; j < sz; ++j) {
                    result.push_back(result[j]);
                    result.back()[i] ^= 32; // Single-cycle case toggle
                }
            }
        }

        return result;
    }
};