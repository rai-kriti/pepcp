#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll nb, ns, nc;
ll pb, ps, pc;
ll r;
ll cb = 0, cs = 0, cc = 0;

bool check(ll x) {
    ll buyB = max(0LL, cb * x - nb);
    ll buyS = max(0LL, cs * x - ns);
    ll buyC = max(0LL, cc * x - nc);

    ll cost = buyB * pb + buyS * ps + buyC * pc;

    return cost <= r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string recipe;
    cin >> recipe;

    for (char ch : recipe) {
        if (ch == 'B') cb++;
        else if (ch == 'S') cs++;
        else cc++;
    }

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    ll low = 0, high = 1e13, ans = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans;
}