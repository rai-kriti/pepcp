#include <bits/stdc++.h>
using namespace std;

bool possible(long long n, long long m, long long day) {
    long long eaten = day * (day + 1) / 2;
    
    long long added = m * day;

    // grains after day days ignoring overflow
    return n + added - eaten <= 0;
}

long long binarySearch(long long n, long long m) {

    long long low = 1, high = 2e9;
    long long ans = -1;

    while(low <= high) {

        long long mid = low + (high-low)/2;

        if(possible(n,m,mid)) {
            ans = mid;
            high = mid - 1; // find first day
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    cin>>n>>m;

    cout << binarySearch(n,m);

    return 0;
}