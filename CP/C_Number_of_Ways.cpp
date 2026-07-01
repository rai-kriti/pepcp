// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     vector<long long> a(n), pref(n);

//     for(int i = 0; i < n; i++)
//         cin >> a[i];

//     pref[0] = a[0];
//     for(int i = 1; i < n; i++)
//         pref[i] = pref[i-1] + a[i];

//     long long sum = pref[n-1];

//     if(sum % 3 != 0){
//         cout << 0;
//         return 0;
//     }

//     long long target = sum / 3;

//     vector<long long> cnt(n,0);

//     if(pref[n-2] == 2 * target)
//         cnt[n-2] = 1;

//     for(int i = n-3; i >= 0; i--){
//         cnt[i] = cnt[i+1];
//         if(pref[i] == 2 * target)
//             cnt[i]++;
//     }

//     long long ans = 0;

//     for(int i = 0; i < n-2; i++){
//         if(pref[i] == target)
//             ans += cnt[i+1];
//     }

//     cout << ans;
// }




#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n), pref(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    pref[0] = a[0];
    for(int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i];

    long long sum = pref[n - 1];

    if(sum % 3 != 0){
        cout << 0;
        return 0;
    }

    long long target = sum / 3;
    long long ways = 0;
    long long ans = 0;

    for(int i = n - 2; i >= 1; i--){
        if(pref[i] == 2 * target)
            ways++;

        if(pref[i - 1] == target)
            ans += ways;
    }

    cout << ans;
}