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
bool multi = 0;

ll a[MAX], b[MAX], c[MAX], a1[MAX];
void Solve() {
    ll n; cin >> n;
    ll summ = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        a1[i] = a[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] != i) {
            ll j = i;
            while(j != a[j]) {
                b[++ summ] = j;
                c[summ] = a[j];
                swap(a[j], a[a[j]]);
            }
        }
    }
    cout << summ << "\n";
    for(ll i = 1; i <= summ; i ++ ) {
        cout << b[i] << " " << c[i] << "\n";
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