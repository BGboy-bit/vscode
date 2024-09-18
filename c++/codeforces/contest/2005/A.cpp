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
    ll x = n / 5;
    ll y = n - x * 5;
    vector<ll> a(5, x);
    string s = "aeiou";
    for(ll i = 0; i < y; i ++ ) {
        a[i] ++ ;
    }
    for(ll i = 0; i <= 4; i ++ ) {
        for(ll j = 1; j <= a[i]; j ++ ) {
            cout << s[i];
        }
    }
    cout << "\n";
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