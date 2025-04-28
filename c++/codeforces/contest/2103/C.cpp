#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1), b(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[i] > k) 
            b[i] -- ;
        else 
            b[i] ++ ;
    }
    ll res1 = 100, pos1 = -1;
    for(ll i = 1; i < n; i ++ ) {
        b[i] += b[i - 1];
        if(b[i] < 0) 
            continue;
        if(res1 > b[i]) {
            res1 = b[i]; 
            if(pos1 == -1)
                pos1 = i;
            continue; 
        }
        if(res1 > -1 && b[i] >= res1) {
            cout << "Yes\n"; return ;
        }
    } 
    vector<ll> c(n + 2, 0);
    for(ll i = n; i >= 1; i -- ) {
        if(a[i] > k) 
            c[i] -- ;
        else 
            c[i] ++ ;
    }
    ll res2 = 100, pos2 = -1;
    for(ll i = n; i >= 2; i -- ) {
        c[i] += c[i + 1];
        if(c[i] < 0) 
            continue;
        if(res2 > c[i]) {
            res2 = c[i];
            if(pos2 == -1)
                pos2 = i;             
            continue;
        }
        if(res2 > -1 && c[i] >= res2) {
            cout << "Yes\n"; return ;
        }
    }
    if(pos1 > -1 && pos2 > -1 && pos1 < pos2) {
        cout << "Yes\n"; return ;
    }
    cout << "No\n";
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