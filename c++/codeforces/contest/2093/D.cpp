#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

void Solve() {
    ll n, q; cin >> n >> q;
    while(q -- ) {
        string s; cin >> s;
        if(s == "->") {
            ll row, col; cin >> row >> col;
            row = (1 << n) - row; col = (1 << n) - col;
            ll z = (1 << n);
            vector<ll> od;
            while((z >>= 1) > 0) {
                ll a = row & z, b = col & z;
                if(a != 0 && b != 0) {
                    od.push_back(1);
                } else if(a == 0 && b == 0) {
                    od.push_back(2);
                } else if(a == 0 && b != 0) {
                    od.push_back(3);
                } else if(a != 0 && b == 0) {
                    od.push_back(4);
                }
            }
            ll l = 1, r = 1ll << (2 * n);
            for(auto x : od) {
                ll a = (r - l + 1) / 4;
                l += a * (x - 1);
                r -= a * (4 - x);
            }
            cout << l << "\n";
        } else {
            ll d; cin >> d;
            ll l = 1, r = 1ll << (2 * n);
            vector<ll> od;
            while(l < r) {
                ll x = (r - l + 1) / 4;
                ll y = l + x - 1;
                ll cnt = 1;
                while(d > y) {
                    y += x; cnt ++ ;
                }
                l = y - x + 1; r = y; 
                od.push_back(cnt);
            }
            ll row = 1 << n, col = 1 << n;
            ll y = 1 << n;
            for(auto x : od) {
                y >>= 1;
                if(x == 1) {
                    row -= y; col -= y;
                } else if(x == 3) {
                    col -= y; 
                } else if(x == 4) {
                    row -= y;
                }
            }
            cout << row << " " << col << "\n";
        }
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
