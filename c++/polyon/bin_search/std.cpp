#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pll;

const int MAX = 1e5 + 10;
pll p[MAX];
ll u[MAX], v[MAX];
ll n, m;

bool Check(ll mid) {
	vector<ll> a(n + 1, 0);
	a[1] = -1;   
    for(ll i = 1; i <= mid; i ++ ) {
		a[u[i]] ++ ;  a[v[i] + 1] -- ; 
    }
    for(ll i = 1; i <= n; i ++ ) {
		a[i] += a[i - 1];
	}
	for(ll i = 1; i <= n; i ++ ) {
		if(a[i] >= 0) a[i] = 1;
		else if(a[i] < 0) a[i] = -1;
		a[i] += a[i - 1];
	} 
	// for(ll i = 1; i <= n; i ++ ) cout << a[i] << " \n"[i == n];
    for(ll i = 1; i <= m; i ++ ) {
        if(a[p[i].second] - a[p[i].first - 1] > 0) return true; 
    }
    return false;
}

void Solve() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++ ) {
        cin >> p[i].first >> p[i].second;
    }
    ll q;
    cin >> q;
    for(ll i = 1; i <= q; i ++ ) {
        cin >> u[i] >> v[i];
    }
    ll l = 1, r = q; 
    while(l < r) {
        ll mid = l + r >> 1;
        if(Check(mid)) r = mid;
        else l = mid + 1;
    }
    if(Check(l)) cout << l << "\n";
    else cout << "-1" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}
