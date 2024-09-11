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
    string s; cin >> s;
    bool ac = 1;
    ll f1 = 0, f2 = 0;
    ll cnt1 = 0, cnt2 = 0;
    for(ll i = 0; i < s.size(); i ++ ) {
        if(s[i] == 'a') {
            if(f1 == 3 && f2 == 0) {
                f1 = 0; cnt2 ++ ;
            }
            if(f1 % 2 == 0 || f2 % 2 == 0) {
                if(f1 % 2 == 0) f1 ++ ;
                if(f2 % 2 == 0) f2 ++ ;
                if(f2 == 3) {
                    f2 = 0; if(i == s.size() - 1) cnt2 ++ ;
                }
                if(f1 == 5) {
                    f1 = 0; f2 = 0; cnt1 ++ ;
                }
            } else {
                ac = 0; break;
            }
        }
        else if(s[i] == 'v') {
            if(f1 % 2 == 1 || f2 % 2 == 1) {
                if(f1 % 2 == 1) f1 ++ ;
                if(f2 % 2 == 1) f2 ++ ;
            } else {
                ac = 0; break;
            }            
        } else {
            ac = 0; break;
        }
    }
    if(ac && cnt1 * 5 + cnt2 * 3 == s.size()) cout << "Yes\n";
    else cout << "No\n";
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