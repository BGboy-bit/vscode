#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//多组输入

void Solve() {
    ll n; cin >> n;
    ll a[30], b[30];
    ll maxx = 0, mxp, minn = inf, mnp;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        b[i] = a[i];
        if(a[i] > 0) { 
            if(maxx < a[i]) {
                maxx = a[i]; mxp = i;    
            }
        }
        else {
            if(minn > a[i]) {
                minn = a[i]; mnp = i;
            }
        }
    }
    if(maxx == 0) {
        cout << n - 1 << "\n";
        for(ll i = n; i > 1; i -- ) cout << i - 1 << " " << i << "\n";
        return ;
    }
    if(minn == inf) {
        cout << n - 1 << "\n";
        for(ll i = 1; i < n; i ++ ) cout << i + 1 << " " << i << "\n";
        return ; 
    }
    vector<pair<ll, ll>> vp; 
    while(maxx < abs(minn)) {
        vp.push_back({mxp, mxp});
        maxx *= 2; b[mxp] *= 2;
    }
    for(ll i = 1; i <= n; i ++ ) {//全部转换为正数
        if(b[i] < 0) {vp.push_back({i, mxp}); b[i] += maxx;}
        
    }
    for(ll i = 2; i <= n; i ++ ) {
        if(b[i] < b[i - 1]) {vp.push_back({i, i - 1}); b[i] += b[i - 1];}
        
    }
    if(vp.size() > 31) {
        vp.clear();
        while(abs(minn) < maxx) {
            vp.push_back({mnp, mnp});
            minn *= 2; a[mnp] *= 2;
        }
        for(ll i = 1; i <= n; i ++ ) {//全部转换为负数
            if(a[i] > 0) {vp.push_back({i, mnp}); a[i] += minn; }
        }
        
        for(ll i = n - 1; i >= 1; i -- ) {
            if(a[i] > a[i + 1]) {vp.push_back({i, i + 1}); a[i] += a[i + 1];}
        }
    }
    cout << vp.size() << "\n";
    for(auto i : vp) {
        cout << i.first << " " << i.second << "\n";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}