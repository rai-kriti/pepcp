#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int q;
    cin >> q;

    while (q--) {
        int m;
        cin >> m;

        cout << upper_bound(arr.begin(), arr.end(), m) - arr.begin() << '\n';
    }

    return 0;
}