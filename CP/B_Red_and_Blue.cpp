#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sum = 0, mxR = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            mxR = max(mxR, sum);
        }

        int m;
        cin >> m;

        sum = 0;
        int mxB = 0;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            sum += x;
            mxB = max(mxB, sum);
        }

        cout << mxR + mxB << "\n";
    }

    return 0;
}