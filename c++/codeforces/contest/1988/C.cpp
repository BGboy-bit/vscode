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

ll b2[62];

void Solve() {
    ll n; cin >> n;
    ll m = n;
    vector<ll> a;
    for(ll i = 61; i >= 0; i -- ) {
        if(n >= b2[i]) {
            a.push_back(i);
            n -= b2[i];
        }
    }
    if(a.size() == 1) {
        cout << "1\n" << b2[a[0]] << "\n"; 
        return ;
    }
    cout << a.size() + 1 << "\n";
    for(ll i = 0; i < a.size(); i ++ ) {
        cout << m - b2[a[i]] << " ";
    }
    cout << m << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    b2[0] = 1;
    for(ll i = 1; i <= 61; i ++ ) b2[i] = b2[i - 1] * 2;
    while(T -- ) {
        Solve();
    }
    return 0;
}