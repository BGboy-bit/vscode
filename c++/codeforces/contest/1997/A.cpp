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
    bool ff = 0;
    cout << s[0];
    for(ll i = 1; i < s.size(); i ++ ) {
        if(s[i] == s[i - 1] && !ff) {
            if(s[i] < 'z') cout << 'z';
            else cout << 'a';
            ff = 1;
        }
        cout << s[i];
    }
    if(!ff) {
        if(s.back() != 'z') cout << "z\n";
        else cout << "a\n";
    } else cout << "\n";
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