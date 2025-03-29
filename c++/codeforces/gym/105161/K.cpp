#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, inf = 2E18 + 10;

void solve()
{
    ll n; cin >> n;
    vector<ll> a(n + 1);
    ll x = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        x = max(x, a[i]);
    }
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] == x) cnt ++ ;
    }
    if(cnt % 2 == 0) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
}