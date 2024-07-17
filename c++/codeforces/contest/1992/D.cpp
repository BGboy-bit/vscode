#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s; s = '!' + s;
    ll i = 0;
    while(i <= n) {
        if(i == n) {
            if(s[i] == 'L' || s[i] == 'W' && k > 0) 
                cout << "Yes" << "\n";
            else 
                cout << "No" << "\n";
            return;
        }
        if(s[i + 1] == 'L') i ++ ;
        else {
            // jump
            ll x = m + i;
            for(i = i + 1; i <= x; i ++ ) {
                if(i == n && i < x) {
                    cout << "Yes" << "\n";
                    return ;
                }
                if(s[i] == 'L'|| i == x || i == n) {
                    break;
                }
            }
            // swim
            if(s[i] == 'C') {
                cout << "No" << "\n";
                return ;
            } else if(s[i] == 'W') {
                while(s[i] != 'L') {
                    k -- ; 
                    if(s[i] == 'C' || k < 0) {
                    cout << "No" << "\n";
                        return ;
                    }
                    if(i == n) {
                        cout << "Yes" << "\n";
                        return ;
                    }
                    i ++ ;
                } 

            }
        }
    }
}


signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}