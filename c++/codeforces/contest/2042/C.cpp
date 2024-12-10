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
    ll n, k; cin >> n >> k;
    string s; cin >> s; s = "!" + s;
    vector<ll> a;
    ll ves = 0;
    for(ll i = n; i > 1; i -- ) {
        if(s[i] == '1')
            ves ++ ;
        else 
            ves -- ;
        if(ves > 0) a.push_back(ves);
    }
    if(a.size() == 0) {
        cout << "-1\n"; return ;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll ans = 1;
    for(auto i : a) {
        k -= i; ans ++ ;
        if(k <= 0) {
            cout << ans << "\n"; return ;
        }
    }
    cout << "-1\n";
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