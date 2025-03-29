#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll x, y; cin >> x >> y;
    vector<ll> b1, b2;
    while(x > 0) {
        if(x % 2 == 1) {
            b1.push_back(1);
        } else {
            b1.push_back(0);
        }
        x /= 2;
    }
    while(y > 0) {
        if(y % 2 == 1) {
            b2.push_back(1);
        } else {
            b2.push_back(0);
        }
        y /= 2;
    }  
    if(b1.size() < b2.size()) {
        swap(b1, b2);
    }
    ll n = b1.size(), m = n;
    vector<ll> b3(n + 1);
    for(ll i = 1; i <= n - m; i ++ ) {
        b2.push_back(0);
    }
    for(ll i = 0; i < n; i ++ ) {
        while(b1[i] == 1 && b2[i] == 1) {
            if(i == n - 1) {
                cout << "-1\n"; return ;
            }
            if(i > 0 && b1[i - 1] ^ b2[i - 1] == 1) {
                b3[i - 1] = 1;
                if(b1[i - 1] == 1) {
                    b1[i] = 0;
                    if(i < n - 1) {
                        b1[i + 1] = 1;
                    } else {
                        b1.push_back(1); n ++ ;
                        b3.push_back(0);
                    }
                } else {
                    b2[i] = 0;
                    if(i < m - 1) {
                        b2[i + 1] = 1;
                    } else {
                        b2.push_back(1); m ++ ;
                        b3.push_back(0);
                    }                  
                }
            } 
            else {
                b3[i] = 1; 
                ll res = i;
                while(res < n - 1 && b1[res] == 1) {
                    b1[res ++ ] = 0;
                }
                if(b1[res] == 1) {
                    b1[res] = 0; b1.push_back(1); n ++ ;
                    b3.push_back(0);
                } else {
                    b1[res] = 1;
                }
                res = i; 
                while(res < m - 1 && b2[res] == 1) {
                    b2[res ++ ] = 0;
                }
                if(b2[res] == 1) {
                    b2[res] = 0; b2.push_back(1); m ++ ;
                }else {
                    b2[res] = 1;
                }
            }
            if(n < m) {
                b1.push_back(0); n ++ ;
                b3.push_back(0);
            } else if(m < n) {
                b2.push_back(0); m ++ ;
            }
        }
    }
    ll k = 0;
    for(ll i = 0; i < b3.size(); i ++ ) {
       if(b3[i]) k += (1 << i);
    }
    cout << k << "\n";
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