#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

vector<vector<ll>> a(MAX, vector<ll>());
ll k;
ll ans = inf;
ll mn;
ll cnt[MAX];

inline ll read() {
	char ch = getchar(); ll x = 0, f = 1;
	while(ch < '0'||ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while('0'<=ch && ch <= '9') {x = x * 10+ ch - '0'; ch = getchar();}
	return x * f;
}

void dfs(ll l, ll r, ll res) {
    if(r - l >= cnt[res]) return;
    else cnt[res] = r - l;
    if(res == mn) {
        if(mn != k - 1) dfs(l, r, res + 1);
        else ans = min(r - l, ans); 
        return ;
    } 
    if(a[res].size() == 1 ) {
        if(res != k - 1) {
            if(a[res][0] >= l && a[res][0] <= r) dfs(l, r, res + 1);
            else if(a[res][0] < l) dfs(a[res][0], r, res + 1);
            else if(a[res][0] > r) dfs(l, a[res][0], res + 1);
        }
        else {
            if(a[res][0] >= l && a[res][0] <= r) ans = min(r - l, ans);
            else if(a[res][0] < l) ans = min(r - a[res][0], ans);
            else if(a[res][0] > r) ans = min(a[res][0] - l, ans);
        }
        return;
    } 

    ll L = -inf; ll R = inf;
    bool f = 0;
    //二分找左边最大
    ll l1 = 0, r1 = a[res].size() - 1;
    while(l1 < r1) {
        ll mid = l1 + r1 >> 1;
        if(a[res][mid] >= l && a[res][mid] <= r) {
            if(res != k - 1) dfs(l, r, res + 1); 
            else ans = min(ans, r - l);
            f = 1;
            break; 
        }
        else if(a[res][mid] >= l) r1 = mid - 1;
        else l1 = mid;
    }
    if(a[res][l1] < l) L = a[res][l1];
    if(f) return ;

    //二分找右边最小
    l1 = 0, r1 = a[res].size() - 1;
    while(l1 < r1) {
        ll mid = l1 + r1 >> 1;
        if(a[res][mid] >= l && a[res][mid] <= r) {
            if(res != k - 1) dfs(l, r, res + 1); 
            else ans = min(ans, r - l);
            f = 1;
            break; 
        }
        else if(a[res][mid] <= r) l1 = mid + 1; 
        else r1 = mid;
    }
    if(a[res][r1] > r) R = a[res][r1];
    if(f) return ;

    else if(res == k - 1) {
        ans = min(ans, min(r - L, R - l));
    }
    else {
        if(l - L == R - r) {
            dfs(l, R, res + 1);
            dfs(L, r, res + 1);
        } 
        else if(l - L < R - r) dfs(L, r, res + 1);
        else if(R - r < l - L) dfs(l, R, res + 1);
    }
}

void Solve() {
    ans = inf;
    a.clear();
    // cin >> k;
    k = read();
    ll minn = inf; mn = 0;
    for(ll i = 0; i < k ; i ++ ) {
        cnt[i] = inf;
        ll c;
        // cin >> c;
        c = read();
        if(c < minn) {mn = i; minn = c;}
        vector<ll> v(c);
        for(ll j = 0; j < c; j ++ ) {
            // cin >> v[j];
            v[j] = read();
        }
        sort(v.begin(), v.end());
        a[i] = v;
    }
    if(k == 1) {
        cout << "0" << "\n";
        return ;
    }
    for(auto i : a[mn]) {
        dfs(i, i, 0);
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    T = read();
    while(T --) {
        Solve();
    }
    return 0;
}
