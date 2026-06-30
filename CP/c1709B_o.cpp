#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> forward(n, 0), backward(n, 0);

    // Left -> Right prefix damage
    for (int i = 1; i < n; i++) {
        forward[i] = forward[i - 1];

        if (arr[i - 1] > arr[i]) {
            forward[i] += arr[i - 1] - arr[i];
        }
    }

    // Right -> Left prefix damage
    for (int i = n - 2; i >= 0; i--) {
        backward[i] = backward[i + 1];

        if (arr[i + 1] > arr[i]) {
            backward[i] += arr[i + 1] - arr[i];
        }
    }

    while (m--) {

        int l, r;
        cin >> l >> r;

        l--;
        r--;

        if (l < r)
            cout << forward[r] - forward[l] << "\n";
        else
            cout << backward[r] - backward[l] << "\n";
    }

    return 0;
}