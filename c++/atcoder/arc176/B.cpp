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

ll d2[] = {6, 2, 4, 8};

void Solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll n1 = d2[n % 4], n2 = d2[m % 4], n3 = d2[k % 4];
    ll n4 = abs(n2 - n3);
    for(ll i = 0; i < 4; i ++ ) {
        if((n4 * d2[i]) % 10 == n1) {cout << d2[i] << "\n"; break;} 
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}