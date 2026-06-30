#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (m--) {

        int l, r;
        cin >> l >> r;

        l--;
        r--;

        long long dam = 0;

        if (l < r) {

            for (int i = l; i < r; i++) {
                if (arr[i] > arr[i + 1]) {
                    dam += arr[i] - arr[i + 1];
                }
            }

        } else {

            for (int i = l; i > r; i--) {
                if (arr[i] > arr[i - 1]) {
                    dam += arr[i] - arr[i - 1];
                }
            }

        }

        cout << dam << "\n";
    }

    return 0;
}