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

struct pr {
    ll loc;
    ll val;
};
bool cmp(const pr& a, const pr& b) {
    return a.val < b.val;
}

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), ans1(n + 1), ans2(n + 1);
    // 2
    vector<pr> p11, p12;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(i % 2 == 1) p11.push_back({i, a[i]});
        else p12.push_back({i, a[i]});
    }
    sort(p11.begin(), p11.end(), cmp);
    sort(p12.begin(), p12.end(), cmp);
    ll res = 1;
    for(ll i = p11.size() - 1; i >= 0; i -- ){
        ans1[p11[i].loc] = res ++ ; 
    }
    for(ll i = p12.size() - 1; i >= 0; i -- ){
        ans1[p12[i].loc] = res ++ ; 
    }
    ll cnt1 = 0;
    for(ll i = 2; i < n; i ++ ) {
        if(ans1[i] + a[i] > ans1[i - 1] + a[i - 1] && ans1[i] + a[i] > ans1[i + 1] + a[i + 1]) {
            cnt1 ++ ;
        } 
    }
    // 3
    vector<pr> p21, p22;
    for(ll i = 1; i <= n; i ++ ) {
        if(i % 2 == 0) p22.push_back({i, a[i]});
        else p21.push_back({i, a[i]});
    }
    sort(p21.begin(), p21.end(), cmp);
    sort(p22.begin(), p22.end(), cmp);
    res = 1;
    for(ll i = p22.size() - 1; i >= 0; i -- ){
        ans2[p22[i].loc] = res ++ ; 
    }
    for(ll i = p21.size() - 1; i >= 0; i -- ){
        ans2[p21[i].loc] = res ++ ; 
    }
    ll cnt2 = 0;
    for(ll i = 2; i < n; i ++ ) {
        if(ans2[i] + a[i] > ans2[i - 1] + a[i - 1] && ans2[i] + a[i] > ans2[i + 1] + a[i + 1]) {
            cnt2 ++ ;
        } 
    } 
    if(cnt1 >= cnt2) {
        for(ll i = 1; i <= n; i ++ ) cout << ans1[i] << " ";
        cout << "\n";
    } else {
        for(ll i = 1; i <= n; i ++ ) cout << ans2[i] << " ";
        cout << "\n";
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