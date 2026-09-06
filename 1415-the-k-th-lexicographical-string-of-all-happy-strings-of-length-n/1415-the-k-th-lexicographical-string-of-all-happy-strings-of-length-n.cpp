class Solution {
public:
    string getHappyString(int n, int k) {

        int total = 3 * (1 << (n - 1));

        if (k > total)
            return "";

        string ans;
        char prev = '#';

        for (int pos = 0; pos < n; pos++) {

            int remaining = n - pos - 1;
            int blockSize = 1 << remaining;

            for (char ch = 'a'; ch <= 'c'; ch++) {

                if (ch == prev)
                    continue;

                if (k > blockSize) {
                    k -= blockSize;
                } 
                else {
                    ans += ch;
                    prev = ch;
                    break;
                }
            }
        }

        return ans;
    }
};