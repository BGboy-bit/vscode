#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    map<pair<ll, ll>, ll> mp;
    pair<ll, ll> b0 = {1, 1}, b1 = {1, 1};
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] == 0) {
            while(mp[b0] == 1) {
                if(b0.second > 1) {
                    b0.first += 3;
                    b0.second -= 3;
                } else {
                    swap(b0.first, b0.second);
                    b0.second += 3;
                }
            }
            mp[b0] = 1;
            cout << b0.first << " " << b0.second << "\n";
        } else if(a[i] == 1) {
            ll z = b1.first + b1.second;
            while(mp[b1] == 1) {
                z = b1.first + b1.second;
                if(z % 3 == 0) { // 左上/右下/右上
                    if((b1.first - 1) % 3 == 0) { // 左上
                        if(b1.second - 2 > 0) {
                            b1.first += 2; b1.second -= 2;
                        } else {
                            b1.first += 1; b1.second -= 1; 
                        }
                    } else { // /右下/右上
                        if(b1.second == 1) {
                            swap(b1.first, b1.second);
                            b1.second += 2;
                        } else { // 右上
                            if(b1.second % 3 == 0) {
                                b1.first -= 1; b1.second += 1;
                            } else { // 右下
                                b1.first += 2; b1.second -= 2;
                            }   
                        } 
                    }
                } else if(z % 3 == 2) { // 左下
                    if(b1.second > 1) {
                        b1.first += 3; b1.second -= 3;
                    } else {
                        swap(b1.first, b1.second);
                        b1.second += 1;
                    }
                }
            }
            mp[b1] = 1;
            bool ff = 1;
            if(z % 3 == 0) {
                if(b1.first % 3 == 0 || b1.second % 3 == 0) {
                    cout << b1.first - 1 << " " << b1.second - 1 << "\n"; ff = 0;
                }
            }
            if(ff) {
                cout << b1.first << " " << b1.second << "\n";
            }
        }
    }
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}