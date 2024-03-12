#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

struct node {
    ll l, r;
}u, v;

ll n, m;
string s;
ll pre0[MAX], suf1[MAX];
void Solve() {
    cin >> n >> m;
    cin >> s;
    s = "?" + s;
    for(ll i = 1, pos = 0; i <= n; i ++ ) {
        if(s[i] == '1') pre0[i] = pos;
        else pos = i;
    }
    for(ll i = n, pos = n + 1; i >= 1; i -- ) {
        if(s[i] == '0') suf1[i] = pos;
        else pos = i;
    }

    set<pair<ll, ll>> st;
    for(ll i = 1; i <= m; i ++ ) {
        ll l, r; pair<ll, ll> p;
        cin >> l >> r;
        if(s[l] == '0') l = suf1[l];
        if(s[r] == '1') r = pre0[r];
        if(l >= r) {p.first = 0; p.second = 0;}
        else p.first = l, p.second = r;
        st.insert(p);
    }
    cout << st.size() << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}