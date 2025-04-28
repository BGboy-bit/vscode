#include<bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
using pii = pair<int,int>;

constexpr ll N =2E6 + 10, inf = 2E18 + 10;

void solve()
{
    ll n; cin >> n;
    vector<pair<ll, ll>> a, b;
    for(ll i = 1; i <= n; i ++ ) {
        ll a1, b1, c1, d1; cin >> a1 >> b1 >> c1 >> d1;
        if(c1 == 0) {
            b.push_back({b1, i});
        } else if(d1 == 0) {
            a.push_back({a1, i});
        } else if(a1 > b1) {
            b.push_back({b1, i});
        } else if(b1 > a1) {
            a.push_back({a1, i});
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a.size() << " ";
    for(ll i = 0; i < a.size(); i ++ ) {
        cout << a[i].second << " \n"[i == a.size() - 1];
    }
    cout << b.size() << " ";
    for(ll i = 0; i < b.size(); i ++ ) {
        cout << b[i].second << " \n"[i == b.size() - 1];
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

    return 0;
}