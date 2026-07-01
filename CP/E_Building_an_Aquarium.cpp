#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &corals, long long mid, long long maxwater){
    long long water = 0;

    for(int h : corals){
        if(h < mid)
            water += mid - h;

        if(water > maxwater) 
            return false;
    }

    return true;
}

long long binarysearch(vector<int> &corals, long long maxwater){

    long long low = 1;
    long long high = 2e9 + 1;
    long long ans = 1;

    while(low <= high){

        long long mid = low + (high-low)/2;

        if(possible(corals, mid, maxwater)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        int n;
        long long x;

        cin >> n >> x;

        vector<int> corals(n);

        for(int i=0;i<n;i++)
            cin >> corals[i];

        cout << binarysearch(corals, x) << '\n';
    }

    return 0;
}