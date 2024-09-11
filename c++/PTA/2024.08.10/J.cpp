#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    // ll n = 2;
    vector<ll> a(n + 1);
    vector<vector<ll>> b2(100);
    ll s;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1, cnt = 0; j <= a[i]; j *= 2, cnt ++ ) {
            if(a[i] & j) {
                b2[cnt].push_back(i);
            }
        }
        if(i == 1) s = a[i];
        else s ^= a[i];
    }
    if(s != 0) {
        cout << "-1\n"; return ;
    }
    vector<ll> b;
    for(ll i = 64; i >= 0; i -- ) {
        if(b2[i].size() == 0) continue;
        if(b2[i].size() != 2) {
            cout << "-1\n"; return;
        }
        ll x = b2[i][1], y = b2[i][0];
        if(a[x] > a[y]) swap(x, y);
        ll z = a[y] - (a[y] ^ a[x]);
        for(ll j = 1, cnt = 0; j <= a[y]; j *= 2, cnt ++ ) {
            if(a[y] & j) {
                auto new_end = remove(b2[cnt].begin(), b2[cnt].end(), y);
                b2[cnt].erase(new_end);
            }
        }
        a[y] ^= a[x];
        for(ll j = 1, cnt = 0; j <= a[y]; j *= 2, cnt ++ ) {
            if(a[y] & j) {
                b2[cnt].push_back(y);
            }
        }
        for(ll j = 1, cnt = 0; j <= a[x]; j *= 2, cnt ++ ) {
            if(a[x] & j) {
                auto new_end = remove(b2[cnt].begin(), b2[cnt].end(), x);
                b2[cnt].erase(new_end);
            }
        }
        a[x] = 0;

        b.push_back(y);
        b.push_back(z);
    }
    cout << b.size() / 2 << "\n";
    for(ll i = 0; i < b.size(); i ++ ) {
        cout << b[i];
        if(i % 2 == 0) cout << " ";
        else cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}
/*
1
3
5 3 6

2
3 5
2 3
*/