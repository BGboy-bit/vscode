#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, INF = 2E18 + 10;

void solve()
{
    string s1, s2; cin >> s1 >> s2;
    ll n = s1.size();
    ll st = -1, ed = -1;
    for(ll i = 0; i < n; i ++ ) {
        if(s1[i] != s2[i]) {
            if(st == -1) st = i;
            else ed = i;
        }
    }
    if(ed == -1) ed = st;
    if(st == -1 && ed == -1) {
        vector<ll> d1(n);
        for(ll i = 0, l = 0, r = -1; i < n; i ++ ) {
            ll k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while(0 <= i - k && i + k < n && s1[i - k] == s1[i + k]) {
                k ++ ;
            }
            d1[i] = k -- ;
            if(i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        vector<ll> d2(n);
        for(ll i = 0, l = 0, r = -1; i < n; i ++ ) {
            ll k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while(0 <= i - k - 1 && i + k < n && s1[i - k - 1] == s1[i + k]) {
                k ++ ;
            }
            d2[i] = k -- ;
            if(i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
        ll ans = 0;
        for(ll i = 0; i < n; i ++ ) {
            ans += d1[i];
        }
        for(ll i = 0; i < n; i ++ ) {
            ans += d2[i];
        }
        cout << ans << "\n"; 
        return ;
    } 
    for(ll i = st, j = ed; i <= ed; i ++, j -- ) {
        if(s1[i] != s2[j]) {
            cout << "0\n"; return ;
        }
    }
    ll ans = 1;
    for(ll i = st - 1, j = ed + 1; i >= 0 && j < n; i -- , j ++ ) {
        if(s1[i] != s1[j]) {
            break;
        } else ans ++ ;
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}