#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 110;
ll k, n;
ll a[MAX];

void bin_search() {
    ll cnt = 0;
    ll l = 0, r = n - 1;
    while(l <= r) {
        cnt ++;
        ll mid = l + r >> 1;
        if(a[mid] == k) {
            cout << cnt << "\n";
            return;
        }
        if(a[mid] > k) r = mid - 1;
        else l = mid + 1; 
    }
    cout << "Not Found" << "\n";
}

void Solve() {
    cin >> k >> n;
    for(ll i = 0; i < n; i ++ ) cin >> a[i];
    bin_search();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}