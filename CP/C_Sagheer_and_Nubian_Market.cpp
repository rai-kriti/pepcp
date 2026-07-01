#include <bits/stdc++.h>
using namespace std;

int n;
long long S;
vector<long long> a;


// calculate minimum cost for buying k items
long long calculateCost(int k) {

    vector<long long> cost(n);

    for(int i = 0; i < n; i++) {
        cost[i] = a[i] + 1LL * (i + 1) * k;
    }

    sort(cost.begin(), cost.end());

    long long sum = 0;

    for(int i = 0; i < k; i++) {
        sum += cost[i];
    }

    return sum;
}


// check if k items are possible
bool isPossible(int k) {

    return calculateCost(k) <= S;

}


// binary search maximum k
int binarySearch() {

    int low = 0;
    int high = n;
    int ans = 0;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(isPossible(mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> S;

    a.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    int k = binarySearch();

    long long total = calculateCost(k);


    cout << k << " " << total << "\n";


    return 0;
}