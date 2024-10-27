#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
using PII = pair<int,int>;

void solve() {
    ll k = 1e8;
    cout << 25 * 26 / 2;
    for(ll i = 30 ; i >= 0; i -- ) {
        if(k & (1ll << i)) {
            cout << i << "\n"; return ;
        }
    }
    
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