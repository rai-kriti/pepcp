#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long lo = 1, hi = 2e9;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            long long notDivisible = mid - mid / n;

            if (notDivisible >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        cout << lo << '\n';
    }

    return 0;
}