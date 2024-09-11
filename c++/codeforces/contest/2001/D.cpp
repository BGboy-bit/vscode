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
    vector<ll> a(n + 1), b, aft(n + 1), c;
    vector<vector<ll>> pos(n + 1), siz(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        if(pos[a[i]].size() == 1) {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end());
    for(auto i : b) {
        aft[pos[i].back()] ++ ;
    }
    for(ll i = n - 1; i >= 1; i -- ) {
        aft[i] = aft[i + 1] + aft[i];
    }
    bool ff = 0;
    ll l = 0, r = b.size() - 1;
    vector<ll> l1, r1;
    ll cnt = b.size(), res = 0;
    while(l < r) {
        if(!ff) {
            if(r1.size() != 0) {
                for(auto i : r1) {
                    ll p = *lower_bound(r1.begin(), r1.end(), res);
                }
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
/*
2
1 2
5
5 1 2 7 9
2
1 2
6
2 7 8 9 1 6
7
9 1 7 5 8 6 4
1
3
4
1 4 6 5
3
4 3 5
4
5 1 4 10
5
2 1 3 4 6
*/