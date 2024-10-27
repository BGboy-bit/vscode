#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
using PII = pair<int,int>;

void solve()
{
    ll k; cin >> k;
    // for(ll k = 20; k <= 30; k ++ ) {
if(k == 0) {
        cout << "4\n3 4 1 2\n"; return ;
    }
    if(k == 1) {
        cout << "6\n1 1 4 5 1 4\n"; return ;
    }
    ll maxx = 0, sum = 0, ans = 0;
    vector<ll> cnt(400, 0);
    int kk=k;
    for(ll i = 30; i >= 1; i -- ) {
        if(sum==0){
            if(kk >= (1ll << i)) {
                cnt[++ maxx] = i;
                if(sum) sum += (1ll << i) - 1;
                else sum += (1ll << i);
                ans += i;
                kk-=(1ll << i);
            }
            continue;
        }
        while(kk >= (1ll << i)-1) {
            cnt[++ maxx] = i;
            if(sum) sum += (1ll << i) - 1;
            else sum += (1ll << i);
            ans += i;
            kk-=(1ll << i)-1;
        }
    }
    ll x = k - sum;
    for(ll i = 30; i >= 1; i -- ) {
        while(x >= (1ll << i) - 1) {
            cnt[++ maxx] = i; 
            x -= (1ll << i) - 1;
            ans += i;
        }
    }
    cout << ans << "\n";
    for(ll i = 1; i < 400; i ++ ) {
        for(ll j = 1; j <= cnt[i]; j ++ ) {
            cout << i << " ";
        }
    }
    cout << "\n";
    // }
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}